/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: battery.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include <iostream>
#include <algorithm>
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

// Stores as much of amountKWh as the battery can take in one hour.
// Returns the amount actually stored.
double Battery::charge(double amountKWh)
{
    double accepted;
    double room;

    if (amountKWh <= 0.0)
    {
        return 0.0;
    }

    room = capacityKWh - chargeKWh;
    accepted = min(amountKWh, maxRateKW);
    accepted = min(accepted, room);

    chargeKWh = chargeKWh + accepted;
    return accepted;
}

// Gives out as much of amountKWh as the battery can supply in one hour.
// Returns the amount actually delivered.
double Battery::discharge(double amountKWh)
{
    double delivered;
    double available;

    if (amountKWh <= 0.0)
    {
        return 0.0;
    }

    available = chargeKWh - minChargeKWh;
    delivered = min(amountKWh, maxRateKW);
    delivered = min(delivered, available);

    chargeKWh = chargeKWh - delivered;
    return delivered;
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
