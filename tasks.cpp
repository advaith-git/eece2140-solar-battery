/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: tasks.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include <iostream>
#include <string>
#include <vector>
#include "tasks.h"
#include "input_reader.h"

using namespace std;

// T1  Owner: Advaith  Status: in progress
void taskLoadSunlight(SimulationState& state)
{
    string filename;
    vector<double> values;

    cout << "Enter sunlight CSV file (example: data/sunlight_sunny.csv): ";
    getline(cin, filename);

    if (!readHourlyCsv(filename, values))
    {
        cout << "Error: could not open " << filename << endl;
        return;
    }

    state.panel.setSunlight(values);
    cout << "Loaded " << values.size() << " hours of sunlight data." << endl;
}

// T2  Owner: Advaith  Status: stub
void taskLoadDemand(SimulationState& state)
{
    (void)state;

    cout << "T2 Load household demand: not implemented yet." << endl;
}

// T3  Owner: Advaith  Status: in progress
// TODO: print the hourly output table and the daily total
void taskSetupPanel(SimulationState& state)
{
    double area;
    double efficiencyPercent;

    area = promptDouble("Enter panel area in m^2 (1 to 200): ", 1.0, 200.0);

    efficiencyPercent = promptDouble("Enter panel efficiency in % (5 to 30): ", 5.0, 30.0);

    state.panel.setSize(area, efficiencyPercent / 100.0);
    state.panel.print();
    cout << "Hourly output table: not implemented yet." << endl;
}

// T4  Owner: Jailen  Status: in progress
// TODO: finish charge() and discharge() in the Battery class
void taskSetupBattery(SimulationState& state)
{
    double capacity;
    double minPercent;
    double maxRate;

    capacity = promptDouble("Enter battery capacity in kWh (1 to 100): ", 1.0, 100.0);

    minPercent = promptDouble("Enter minimum charge in % (0 to 50): ", 0.0, 50.0);

    maxRate = promptDouble("Enter max charge/discharge rate in kW (0.5 to 50): ", 0.5, 50.0);

    state.battery.setLimits(capacity, minPercent, maxRate);
    state.battery.print();
}

// T5  Owner: Advaith and Jailen  Status: stub
void taskRun24Hour(SimulationState& state)
{
    (void)state;

    cout << "T5 Run 24-hour simulation: not implemented yet." << endl;
}

// T6  Owner: Advaith and Jailen  Status: stub
void taskRun7Day(SimulationState& state)
{
    (void)state;

    cout << "T6 Run 7-day simulation: not implemented yet." << endl;
}

// T7  Owner: Jailen  Status: stub
void taskPrintSummary(SimulationState& state)
{
    (void)state;

    cout << "T7 Print summary: not implemented yet." << endl;
}

// T8  Owner: Jailen  Status: stub
void taskSaveResults(SimulationState& state)
{
    (void)state;

    cout << "T8 Save hourly results to CSV: not implemented yet." << endl;
}

// T9  Owner: Advaith and Jailen  Status: stub
void taskCompareBatteries(SimulationState& state)
{
    (void)state;

    cout << "T9 Compare two battery sizes: not implemented yet." << endl;
}
