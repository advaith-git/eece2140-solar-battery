/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: solar_panel.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include <iostream>
#include "solar_panel.h"

using namespace std;

SolarPanel::SolarPanel()
{
    areaM2 = 20.0;
    efficiency = 0.20;
}

bool SolarPanel::setSize(double area, double eff)
{
    if (area <= 0.0 || eff <= 0.0 || eff > 1.0)
    {
        return false;
    }

    areaM2 = area;
    efficiency = eff;
    return true;
}

void SolarPanel::setSunlight(const vector<double>& values)
{
    sunlight = values;
}

int SolarPanel::getHours() const
{
    return static_cast<int>(sunlight.size());
}

// Energy in kWh for one hour: (W/m^2 / 1000) * area * efficiency * 1 h
double SolarPanel::energyAt(int hour) const
{
    if (hour < 0 || hour >= getHours())
    {
        return 0.0;
    }

    return sunlight[hour] / 1000.0 * areaM2 * efficiency;
}

// STUB: will add up energyAt() for every loaded hour
double SolarPanel::totalEnergy() const
{
    return 0.0;
}

void SolarPanel::print() const
{
    cout << "Solar panel: " << areaM2 << " m^2 at "
         << efficiency * 100.0 << "% efficiency, "
         << getHours() << " hours of sunlight loaded" << endl;
}
