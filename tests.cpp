/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: tests.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "tests.h"
#include "solar_panel.h"
#include "battery.h"
#include "load_profile.h"
#include "input_reader.h"

using namespace std;

const double TEST_TOLERANCE = 0.001;

// True if two numbers are equal within the test tolerance
bool nearlyEqual(double a, double b)
{
    return fabs(a - b) < TEST_TOLERANCE;
}

// Prints PASS or FAIL for one test and updates the counts
void check(bool passed, const string& name, int& passCount, int& testCount)
{
    testCount++;

    if (passed)
    {
        passCount++;
        cout << "  PASS  " << name << endl;
    }
    else
    {
        cout << "  FAIL  " << name << endl;
    }
}

// T10  Owner: Jailen  Status: in progress
// SolarPanel, Battery, and LoadProfile tests are written.
// EnergyManager and Report tests come next.
void taskRunTests()
{
    int passCount;
    int testCount;

    passCount = 0;
    testCount = 0;

    cout << "SolarPanel tests" << endl;
    {
        SolarPanel panel;
        vector<double> sun(HOURS_PER_DAY, 0.0);

        panel.setSize(10.0, 0.20);
        panel.setSunlight(sun);
        check(nearlyEqual(panel.energyAt(5), 0.0), "zero sunlight gives zero energy", passCount, testCount);

        sun[12] = 1000.0;
        panel.setSunlight(sun);
        check(nearlyEqual(panel.energyAt(12), 2.0), "1000 W/m^2 on 10 m^2 at 20% gives 2 kWh", passCount, testCount);

        sun[13] = 500.0;
        panel.setSunlight(sun);
        check(nearlyEqual(panel.totalEnergy(), 3.0), "total energy adds every hour", passCount, testCount);
    }

    cout << "Battery tests" << endl;
    {
        Battery battery;

        battery.setLimits(10.0, 10.0, 5.0);
        battery.charge(5.0);
        battery.charge(5.0);
        battery.charge(5.0);
        check(nearlyEqual(battery.getCharge(), 10.0), "charge stops at capacity", passCount, testCount);

        battery.discharge(5.0);
        battery.discharge(5.0);
        battery.discharge(5.0);
        check(nearlyEqual(battery.getCharge(), 1.0), "discharge stops at minimum charge", passCount, testCount);

        check(nearlyEqual(battery.charge(8.0), 5.0), "charge is limited by max rate", passCount, testCount);
    }

    cout << "LoadProfile tests" << endl;
    {
        LoadProfile load;
        vector<double> demand(HOURS_PER_DAY, 1.0);

        demand[18] = 2.5;
        load.setDemand(demand);
        check(nearlyEqual(load.demandAt(18), 2.5), "demandAt returns the stored value", passCount, testCount);
        check(nearlyEqual(load.totalDemand(), 25.5), "total demand adds every hour", passCount, testCount);
        check(nearlyEqual(load.demandAt(30), 0.0), "hour out of range returns 0", passCount, testCount);
    }

    cout << "EnergyManager tests: not written yet" << endl;
    cout << "Report tests: not written yet" << endl;
    cout << passCount << " of " << testCount << " tests passed." << endl;
}
