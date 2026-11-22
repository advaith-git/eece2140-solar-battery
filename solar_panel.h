/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: solar_panel.h
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#ifndef SOLAR_PANEL_H
#define SOLAR_PANEL_H

#include <vector>

// Owner: Advaith Nair
class SolarPanel
{
private:
    double areaM2;
    double efficiency;
    std::vector<double> sunlight;

public:
    SolarPanel();
    bool setSize(double area, double eff);
    void setSunlight(const std::vector<double>& values);
    int getHours() const;
    double energyAt(int hour) const;
    double totalEnergy() const;
    void print() const;
};

#endif
