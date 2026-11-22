/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: report.h
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <vector>
#include "energy_manager.h"

// Owner: Jailen Patel
class Report
{
public:
    void printSummary(const std::vector<HourResult>& results) const;
    bool writeHourlyCsv(const std::vector<HourResult>& results, const std::string& filename) const;
};

#endif
