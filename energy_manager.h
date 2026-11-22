/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: energy_manager.h
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#ifndef ENERGY_MANAGER_H
#define ENERGY_MANAGER_H

#include <vector>
#include "solar_panel.h"
#include "battery.h"
#include "load_profile.h"

// Owner: Advaith Nair and Jailen Patel

// Where the energy went in one hour of the simulation
struct HourResult
{
    int hour;
    double solarKWh;
    double demandKWh;
    double solarToHome;
    double solarToBattery;
    double solarToGrid;
    double batteryToHome;
    double gridToHome;
    double batteryChargeKWh;
};

class EnergyManager
{
private:
    std::vector<HourResult> results;

public:
    bool runSimulation(const SolarPanel& panel, Battery& battery,
                       const LoadProfile& load, int hours);
    const std::vector<HourResult>& getResults() const;
    bool checkBalance(double tolerance) const;
};

#endif
