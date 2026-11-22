/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: report.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/
#include <iostream>
#include <iomanip>
#include "report.h"

using namespace std;

// Prints energy totals for the last run.
// TODO: add the share of demand met by solar, battery, and grid.
void Report::printSummary(const vector<HourResult>& results) const
{
    double totalSolar;
    double totalDemand;
    double totalToGrid;
    double totalFromGrid;

    totalSolar = 0.0;
    totalDemand = 0.0;
    totalToGrid = 0.0;
    totalFromGrid = 0.0;

    for (int h = 0; h < static_cast<int>(results.size()); h++)
    {
        totalSolar = totalSolar + results[h].solarKWh;
        totalDemand = totalDemand + results[h].demandKWh;
        totalToGrid = totalToGrid + results[h].solarToGrid;
        totalFromGrid = totalFromGrid + results[h].gridToHome;
    }

    cout << fixed << setprecision(2);
    cout << "Summary for " << results.size() << " hours" << endl;
    cout << "  Solar produced:     " << totalSolar << " kWh" << endl;
    cout << "  Home demand:        " << totalDemand << " kWh" << endl;
    cout << "  Solar sent to grid: " << totalToGrid << " kWh" << endl;
    cout << "  Taken from grid:    " << totalFromGrid << " kWh" << endl;
    cout.unsetf(ios::fixed);
    cout << setprecision(6);
}

// STUB
bool Report::writeHourlyCsv(const vector<HourResult>& results, const string& filename) const
{
    (void)results;
    (void)filename;

    return false;
}
