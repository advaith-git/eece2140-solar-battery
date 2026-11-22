/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: energy_manager.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include "energy_manager.h"

using namespace std;

// Routes the energy for each hour in the order from the project plan.
// Steps 1 to 3 (solar covers demand) are done.
// TODO: steps 4 and 5, where the battery and then the grid cover a shortfall.
bool EnergyManager::runSimulation(const SolarPanel& panel, Battery& battery,
                                  const LoadProfile& load, int hours)
{
    results.clear();

    if (panel.getHours() < hours || load.getHours() < hours)
    {
        return false;
    }

    battery.reset();

    for (int h = 0; h < hours; h++)
    {
        HourResult result;
        double extra;

        result.hour = h;
        result.solarKWh = panel.energyAt(h);
        result.demandKWh = load.demandAt(h);
        result.solarToHome = 0.0;
        result.solarToBattery = 0.0;
        result.solarToGrid = 0.0;
        result.batteryToHome = 0.0;
        result.gridToHome = 0.0;

        if (result.solarKWh >= result.demandKWh)
        {
            // Step 1: solar covers the home
            result.solarToHome = result.demandKWh;

            // Step 2: extra solar charges the battery
            extra = result.solarKWh - result.demandKWh;
            result.solarToBattery = battery.charge(extra);

            // Step 3: anything left goes to the grid
            result.solarToGrid = extra - result.solarToBattery;
        }
        else
        {
            // Solar covers part of the home. Steps 4 and 5 are not written yet.
            result.solarToHome = result.solarKWh;
        }

        result.batteryChargeKWh = battery.getCharge();
        results.push_back(result);
    }

    return true;
}

const vector<HourResult>& EnergyManager::getResults() const
{
    return results;
}

// Checks that energy in equals energy out for every hour, within tolerance.
// In:  solar + battery to home + grid to home
// Out: demand + solar to battery + solar to grid
// TODO: call this from taskRun24Hour once shortfall hours are handled,
// and add tests for it in tests.cpp.
bool EnergyManager::checkBalance(double tolerance) const
{
    for (int h = 0; h < static_cast<int>(results.size()); h++)
    {
        double energyIn;
        double energyOut;

        energyIn = results[h].solarKWh + results[h].batteryToHome + results[h].gridToHome;
        energyOut = results[h].demandKWh + results[h].solarToBattery + results[h].solarToGrid;

        if (energyIn - energyOut > tolerance || energyOut - energyIn > tolerance)
        {
            return false;
        }
    }

    return true;
}
