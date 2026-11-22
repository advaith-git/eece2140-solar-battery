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
