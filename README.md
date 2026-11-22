# Solar Panel and Battery System Simulator

EECE 2140 Computing Fundamentals for Engineers
Team: Advaith Nair, Jailen Patel

A C++ console program that simulates a home solar panel and battery system hour by hour. Solar powers the home first, extra solar charges the battery, and anything left goes to the grid. When solar is not enough, the battery covers the gap first and the grid covers the rest.

## Status

The menu includes every task. See `docs/EECE2140_Project_Plan.xlsx` for the full task table and the status of each task.

## Build

```
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o solar_sim
```

## Run

```
./solar_sim
```

Run the program from the repository root. When it asks for a file, type the path, for example `data/sunlight_sunny.csv`.

## Input files

Each input file has one header line, then one `hour,value` row per hour starting at hour 0. Files need at least 24 hours.

| File | Column | Units |
|---|---|---|
| `data/sunlight_sunny.csv` | sunlight_wm2 | W/m^2 averaged over the hour |
| `data/sunlight_cloudy.csv` | sunlight_wm2 | W/m^2 averaged over the hour |
| `data/demand_typical.csv` | demand_kwh | kWh used in the hour |

## Repository layout

```
main.cpp                      menu and switch statement
solar_panel.h / .cpp          SolarPanel class
battery.h / .cpp              Battery class
load_profile.h / .cpp         LoadProfile class
energy_manager.h / .cpp       HourResult struct and EnergyManager class
report.h / .cpp               Report class
input_reader.h / .cpp         CSV reading and input prompts
tasks.h / .cpp                one function per menu option (T1 to T9)
tests.h / .cpp                class tests (T10)
data/                         sample input files
docs/                         iteration reports (PDF), Excel project plan, meeting notes
README.md
```
