/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: input_reader.h
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#ifndef INPUT_READER_H
#define INPUT_READER_H

#include <string>
#include <vector>

// Owner: Advaith Nair

const int HOURS_PER_DAY = 24;

bool readHourlyCsv(const std::string& filename, std::vector<double>& values, std::string& errorMessage);
double promptDouble(const std::string& prompt, double minValue, double maxValue);

#endif
