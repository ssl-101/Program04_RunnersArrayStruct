#ifndef RUNNERS_H
#define RUNNERS_H

#include <string>
// structure instead of constants.
struct Runners {
     std::string name;
     double miles[7];
     double total;
     double average;
};

//functions
bool readFile(const std::string& filename, 
     Runner runners[],
     int numRunners,
     int Days_Of_Week);
void calculateTotals(Runner runners[],
     int numRunners,
     int Days_Of_Week);
void displayResults(const Runner runner[],
     int numRunners,
     int Days_Of_Week);

 #endif                   
    