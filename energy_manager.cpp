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

// STUB
bool EnergyManager::checkBalance(double tolerance) const
{
    (void)tolerance;

    return false;
}
