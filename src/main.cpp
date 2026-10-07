#include <iostream>
#include "Runners.h"



using namespace std;

int main() {
    Runner runners[50];
     int NUM_RUNNERS = 0;
     int DAYS_OF_WEEK = 7;
    

    if (!readFile ("runners.txt", runners, NUM_RUNNERS, DAYS_OF_WEEK)) {
        cout<< "Error: Could not open file!\n";
       }
       calculateTotals (runners, NUM_RUNNERS, DAYS_OF_WEEK);
       displayResults(runners, NUM_RUNNERS, DAYS_OF_WEEK);

       return 0;
}

