#ifndef RUNNERS_H
#define RUNNERS_H

#include <string>
// structure instead of constants.
struct Runner{
     std::string name;
     double miles[7];
     double total;
     double average;
};

//functions
bool readFile(const std::string& filename, 
     Runner runners[],
     int& numRunners,
     int days_of_week);
void calculateTotals(Runner runners[],
     int numRunners,
     int days_of_week);
void displayResults(const Runner runners[],
     int numRunners,
     int days_of_week);

 #endif                   
    