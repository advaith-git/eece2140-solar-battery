/*
EECE 2140 Computing Fundamentals for Engineers
Project Iteration 2: Solar Panel and Battery System
Names: Advaith Nair, Jailen Patel
Date: October 23, 2026

This file holds the whole program for Iteration 2. Each section is marked
with the header and source file it will move to when we split the code
(see the File Structure section of the Iteration 2 report).

Iteration 2 status: the menu runs and every task has a function. Most
tasks are still stubs. T1, T3, and T4 have been started.

Build: g++ -std=c++17 -Wall -Wextra -pedantic solar_sim.cpp -o solar_sim
Run:   ./solar_sim
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

const int HOURS_PER_DAY = 24;


// ======================================================================
// solar_panel.h / solar_panel.cpp      Owner: Advaith Nair
// ======================================================================

class SolarPanel
{
private:
    double areaM2;
    double efficiency;
    vector<double> sunlight;

public:
    SolarPanel();
    bool setSize(double area, double eff);
    void setSunlight(const vector<double>& values);
    int getHours() const;
    double energyAt(int hour) const;
    double totalEnergy() const;
    void print() const;
};

SolarPanel::SolarPanel()
{
    areaM2 = 20.0;
    efficiency = 0.20;
}

bool SolarPanel::setSize(double area, double eff)
{
    if (area <= 0.0 || eff <= 0.0 || eff > 1.0)
    {
        return false;
    }

    areaM2 = area;
    efficiency = eff;
    return true;
}

void SolarPanel::setSunlight(const vector<double>& values)
{
    sunlight = values;
}

int SolarPanel::getHours() const
{
    return static_cast<int>(sunlight.size());
}

// Energy in kWh for one hour: (W/m^2 / 1000) * area * efficiency * 1 h
double SolarPanel::energyAt(int hour) const
{
    if (hour < 0 || hour >= getHours())
    {
        return 0.0;
    }

    return sunlight[hour] / 1000.0 * areaM2 * efficiency;
}

// STUB: will add up energyAt() for every loaded hour
double SolarPanel::totalEnergy() const
{
    return 0.0;
}

void SolarPanel::print() const
{
    cout << "Solar panel: " << areaM2 << " m^2 at "
         << efficiency * 100.0 << "% efficiency, "
         << getHours() << " hours of sunlight loaded" << endl;
}


// ======================================================================
// battery.h / battery.cpp      Owner: Jailen Patel
// ======================================================================

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


// ======================================================================
// load_profile.h / load_profile.cpp      Owner: Advaith Nair
// ======================================================================

class LoadProfile
{
private:
    vector<double> demand;

public:
    void setDemand(const vector<double>& values);
    int getHours() const;
    double demandAt(int hour) const;
    double totalDemand() const;
};

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


// ======================================================================
// energy_manager.h / energy_manager.cpp      Owner: Advaith and Jailen
// ======================================================================

struct HourResult
{
    int hour;
    double solarKWh;
    double demandKWh;
    double solarToHome;
    double solarToBattery;
    double solarToGrid;
    double batteryToHome;
    double gridToHome;
    double batteryChargeKWh;
};

class EnergyManager
{
private:
    vector<HourResult> results;

public:
    bool runSimulation(const SolarPanel& panel, Battery& battery,
                       const LoadProfile& load, int hours);
    const vector<HourResult>& getResults() const;
    bool checkBalance(double tolerance) const;
};

// STUB: routing order planned in the report, to be written together in Phase 3
bool EnergyManager::runSimulation(const SolarPanel& panel, Battery& battery,
                                  const LoadProfile& load, int hours)
{
    (void)panel;
    (void)battery;
    (void)load;
    (void)hours;

    return false;
}

const vector<HourResult>& EnergyManager::getResults() const
{
    return results;
}

// STUB
bool EnergyManager::checkBalance(double tolerance) const
{
    (void)tolerance;

    return false;
}


// ======================================================================
// report.h / report.cpp      Owner: Jailen Patel
// ======================================================================

class Report
{
public:
    void printSummary(const vector<HourResult>& results) const;
    bool writeHourlyCsv(const vector<HourResult>& results, const string& filename) const;
};

// STUB
void Report::printSummary(const vector<HourResult>& results) const
{
    (void)results;
}

// STUB
bool Report::writeHourlyCsv(const vector<HourResult>& results, const string& filename) const
{
    (void)results;
    (void)filename;

    return false;
}


// ======================================================================
// input_reader.h / input_reader.cpp      Owner: Advaith Nair
// ======================================================================

// Reads a two-column CSV file (hour,value) with one header line.
// Right now it only checks that the file opens.
// TODO: check for missing or non-numeric values, negative values,
// hours out of order, and files with fewer than 24 hours.
bool readHourlyCsv(const string& filename, vector<double>& values)
{
    ifstream inFile;
    string line;

    values.clear();
    inFile.open(filename);

    if (!inFile)
    {
        return false;
    }

    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream lineStream(line);
        string hourText;
        string valueText;
        double value;

        getline(lineStream, hourText, ',');
        getline(lineStream, valueText);

        stringstream valueStream(valueText);

        if (valueStream >> value)
        {
            values.push_back(value);
        }
    }

    return true;
}

// Prompts until the user enters a number between minValue and maxValue.
double promptDouble(const string& prompt, double minValue, double maxValue)
{
    double value;

    while (true)
    {
        cout << prompt;

        if (cin >> value && value >= minValue && value <= maxValue)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Please enter a number from " << minValue << " to " << maxValue << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// ======================================================================
// tasks.h / tasks.cpp      One function per menu option
// ======================================================================

struct SimulationState
{
    SolarPanel panel;
    Battery battery;
    LoadProfile load;
    EnergyManager manager;
    Report report;
};

// T1  Owner: Advaith  Status: in progress
void taskLoadSunlight(SimulationState& state)
{
    string filename;
    vector<double> values;

    cout << "Enter sunlight CSV file (example: sunlight_sunny.csv): ";
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

// T10  Owner: Jailen  Status: stub
void taskRunTests(SimulationState& state)
{
    (void)state;

    cout << "T10 Run class tests: not implemented yet." << endl;
}


// ======================================================================
// main.cpp      Menu and switch      Owner: Advaith Nair
// ======================================================================

void printMenu()
{
    cout << endl;
    cout << "===== Solar Panel and Battery Simulator =====" << endl;
    cout << " 1. Load sunlight data from CSV" << endl;
    cout << " 2. Load household demand from CSV" << endl;
    cout << " 3. Set up solar panel and show hourly output" << endl;
    cout << " 4. Set up battery" << endl;
    cout << " 5. Run 24-hour simulation" << endl;
    cout << " 6. Run 7-day simulation" << endl;
    cout << " 7. Print summary of last run" << endl;
    cout << " 8. Save hourly results to CSV" << endl;
    cout << " 9. Compare two battery sizes" << endl;
    cout << "10. Run class tests" << endl;
    cout << " 0. Exit" << endl;
    cout << "Choose an option: ";
}

int main()
{
SimulationState state;
int choice;

choice = -1;

while (choice != 0)
{
    printMenu();

    if (!(cin >> choice))
    {
        if (cin.eof())
        {
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number from the menu." << endl;
        choice = -1;
        continue;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
        case 1:
            taskLoadSunlight(state);
            break;
        case 2:
            taskLoadDemand(state);
            break;
        case 3:
            taskSetupPanel(state);
            break;
        case 4:
            taskSetupBattery(state);
            break;
        case 5:
            taskRun24Hour(state);
            break;
        case 6:
            taskRun7Day(state);
            break;
        case 7:
            taskPrintSummary(state);
            break;
        case 8:
            taskSaveResults(state);
            break;
        case 9:
            taskCompareBatteries(state);
            break;
        case 10:
            taskRunTests(state);
            break;
        case 0:
            cout << "Goodbye." << endl;
            break;
        default:
            cout << "Invalid option. Choose 0 to 10." << endl;
            break;
    }
}

return 0;
}
