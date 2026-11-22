/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: input_reader.cpp
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "input_reader.h"

using namespace std;

// Reads a two-column CSV file (hour,value) with one header line.
// Checks that the file opens, every row has two numbers, hours run
// 0, 1, 2, ... in order, values are not negative, and the file holds
// at least 24 hours. Returns false and fills errorMessage on a problem.
bool readHourlyCsv(const string& filename, vector<double>& values, string& errorMessage)
{
    ifstream inFile;
    string line;
    int lineNumber;
    int expectedHour;

    values.clear();
    inFile.open(filename);

    if (!inFile)
    {
        errorMessage = "Could not open file " + filename + ".";
        return false;
    }

    getline(inFile, line);
    lineNumber = 1;
    expectedHour = 0;

    while (getline(inFile, line))
    {
        lineNumber++;

        if (line.empty() || line == "\r")
        {
            continue;
        }

        stringstream lineStream(line);
        string hourText;
        string valueText;
        int hour;
        double value;

        if (!getline(lineStream, hourText, ',') || !getline(lineStream, valueText))
        {
            errorMessage = "Line " + to_string(lineNumber) + ": expected hour,value.";
            return false;
        }

        stringstream hourStream(hourText);
        stringstream valueStream(valueText);

        if (!(hourStream >> hour) || !(valueStream >> value))
        {
            errorMessage = "Line " + to_string(lineNumber) + ": missing or non-numeric value.";
            return false;
        }

        if (hour != expectedHour)
        {
            errorMessage = "Line " + to_string(lineNumber) + ": expected hour "
                           + to_string(expectedHour) + " but found " + to_string(hour) + ".";
            return false;
        }

        if (value < 0.0)
        {
            errorMessage = "Line " + to_string(lineNumber) + ": value cannot be negative.";
            return false;
        }

        values.push_back(value);
        expectedHour++;
    }

    if (static_cast<int>(values.size()) < HOURS_PER_DAY)
    {
        errorMessage = "File has " + to_string(values.size()) + " hours. At least 24 are needed.";
        values.clear();
        return false;
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
