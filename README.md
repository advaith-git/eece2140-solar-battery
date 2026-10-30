# Solar Panel and Battery System Simulator

EECE 2140 Computing Fundamentals for Engineers
Team: Advaith Nair, Jailen Patel

A C++ console program that simulates a home solar panel and battery system hour by hour. Solar powers the home first, extra solar charges the battery, and anything left goes to the grid. When solar is not enough, the battery covers the gap first and the grid covers the rest.

## Status (Iteration 2)

The menu includes every task and the program compiles and runs. Options 1, 3, and 4 have been started but are not finished. All other options are stubs that print "not implemented yet." See `docs/EECE2140_Project_Plan.xlsx` for the full task table.

## Build

```
g++ -std=c++17 -Wall -Wextra -pedantic solar_sim.cpp -o solar_sim
```

## Run

```
./solar_sim
```

Run the program from the folder that holds the CSV files, or type the path when asked (for example `data/sunlight_sunny.csv`).

## Input files

Each input file has one header line, then one `hour,value` row per hour starting at hour 0. Files need at least 24 hours.

| File | Column | Units |
|---|---|---|
| `data/sunlight_sunny.csv` | sunlight_wm2 | W/m^2 averaged over the hour |
| `data/sunlight_cloudy.csv` | sunlight_wm2 | W/m^2 averaged over the hour |
| `data/demand_typical.csv` | demand_kwh | kWh used in the hour |

## Repository layout

```
solar_sim.cpp        all code for Iteration 2 (split into .h/.cpp files in Iteration 3)
data/                sample input files
docs/                iteration reports (PDF) and the Excel project plan
README.md
```
