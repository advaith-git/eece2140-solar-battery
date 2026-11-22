/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: load_profile.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include "load_profile.h"

using namespace std;

void LoadProfile::setDemand(const vector<double>& values)
{
    demand = values;
}

int LoadProfile::getHours() const
{
    return static_cast<int>(demand.size());
}

double LoadProfile::demandAt(int hour) const
{
    if (hour < 0 || hour >= getHours())
    {
        return 0.0;
    }

    return demand[hour];
}

double LoadProfile::totalDemand() const
{
    double total;

    total = 0.0;

    for (int h = 0; h < getHours(); h++)
    {
        total = total + demand[h];
    }

    return total;
}