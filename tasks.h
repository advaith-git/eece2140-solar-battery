/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: tasks.h
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#ifndef TASKS_H
#define TASKS_H

#include "solar_panel.h"
#include "battery.h"
#include "load_profile.h"
#include "energy_manager.h"
#include "report.h"

// Everything the menu tasks share. One copy lives in main() and is
// passed by reference to each task function.
struct SimulationState
{
    SolarPanel panel;
    Battery battery;
    LoadProfile load;
    EnergyManager manager;
    Report report;
};

// One function per menu option. The owner of each task is listed in tasks.cpp.
void taskLoadSunlight(SimulationState& state);
void taskLoadDemand(SimulationState& state);
void taskSetupPanel(SimulationState& state);
void taskSetupBattery(SimulationState& state);
void taskRun24Hour(SimulationState& state);
void taskRun7Day(SimulationState& state);
void taskPrintSummary(SimulationState& state);
void taskSaveResults(SimulationState& state);
void taskCompareBatteries(SimulationState& state);

#endif
