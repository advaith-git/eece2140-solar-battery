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

// STUB
double LoadProfile::demandAt(int hour) const
{
    (void)hour;

    return 0.0;
}

// STUB
double LoadProfile::totalDemand() const
{
    return 0.0;
}
