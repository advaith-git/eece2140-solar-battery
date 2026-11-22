/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: battery.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include <iostream>
#include "battery.h"

using namespace std;

Battery::Battery()
{
    capacityKWh = 13.5;
    minChargeKWh = 1.35;
    maxRateKW = 5.0;
    chargeKWh = minChargeKWh;
}

bool Battery::setLimits(double capacity, double minPercent, double maxRate)
{
    if (capacity <= 0.0 || minPercent < 0.0 || minPercent >= 100.0 || maxRate <= 0.0)
    {
        return false;
    }

    capacityKWh = capacity;
    minChargeKWh = capacity * minPercent / 100.0;
    maxRateKW = maxRate;
    reset();
    return true;
}

// STUB: will store energy without going over capacity or the rate limit
double Battery::charge(double amountKWh)
{
    (void)amountKWh;

    return 0.0;
}

// STUB: will give out energy without going under the minimum charge or the rate limit
double Battery::discharge(double amountKWh)
{
    (void)amountKWh;

    return 0.0;
}

double Battery::getCharge() const
{
    return chargeKWh;
}

double Battery::getPercent() const
{
    return chargeKWh / capacityKWh * 100.0;
}

void Battery::reset()
{
    chargeKWh = minChargeKWh;
}

void Battery::print() const
{
    cout << "Battery: " << capacityKWh << " kWh capacity, "
         << minChargeKWh << " kWh minimum, "
         << maxRateKW << " kW max rate" << endl;
}
