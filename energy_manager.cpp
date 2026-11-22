/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: energy_manager.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include "energy_manager.h"

using namespace std;

// STUB: routing order is planned in the report
bool EnergyManager::runSimulation(const SolarPanel& panel, Battery& battery,
                                  const LoadProfile& load, int hours)
{
    (void)panel;
    (void)battery;
    (void)load;
    (void)hours;

    return false;
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
