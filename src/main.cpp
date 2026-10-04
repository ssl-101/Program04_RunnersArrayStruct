#include <iostream>
#include "Runners.h"



using namespace std;

int main() {
    const int NUM_RUNNERS = 5;
    const int DAYS_OF_WEEK = 7;
    
    //array
    Runner runners[NUM_RUNNERS];
    string filename = "runners.txt";

    if (!readFile (filename, runners,NUM_RUNNERS, DAYS_OF_WEEK)) {
        cerr << "Error: Could not open file ' " <<filename << " '." << endl;
        return 1;
       }
       calculateTotals (runners, NUM_RUNNERS, DAYS_OF_WEEK);
       displayResults(runners, NUM_RUNNERS, DAYS_OF_WEEK);

       return 0;
}

