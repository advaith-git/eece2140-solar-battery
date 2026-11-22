/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: battery.h
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#ifndef BATTERY_H
#define BATTERY_H

// Owner: Jailen Patel
class Battery
{
private:
    double capacityKWh;
    double minChargeKWh;
    double maxRateKW;
    double chargeKWh;

public:
    Battery();
    bool setLimits(double capacity, double minPercent, double maxRate);
    double charge(double amountKWh);
    double discharge(double amountKWh);
    double getCharge() const;
    double getPercent() const;
    void reset();
    void print() const;
};

#endif
