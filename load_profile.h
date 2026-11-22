/*
EECE 2140 Computing Fundamentals for Engineers
Project: Solar Panel and Battery System
File: load_profile.h
Names: Advaith Nair, Jailen Patel
Date: November 21, 2026
*/

#ifndef LOAD_PROFILE_H
#define LOAD_PROFILE_H

#include <vector>

// Owner: Advaith Nair
class LoadProfile
{
private:
    std::vector<double> demand;

public:
    void setDemand(const std::vector<double>& values);
    int getHours() const;
    double demandAt(int hour) const;
    double totalDemand() const;
};

#endif
