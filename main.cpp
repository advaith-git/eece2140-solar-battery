/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: main.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include <iostream>
#include <limits>
#include "tasks.h"
#include "tests.h"

using namespace std;

// Owner: Advaith Nair
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
            taskRunTests();
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
