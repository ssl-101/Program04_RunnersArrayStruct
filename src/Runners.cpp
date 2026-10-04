#include "Runners.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// added runner struct
struct Runner {
    string name;
    double miles[7];
    double total;
    double average;
};

// Reading file

bool readFile(const string& filename, Runner runners[], int numRunners[], int DAYS_OF_WEEK){
    ifstream inFile(filename);
    if (!inFile){
        return false;
    }

    for(int row = 0; row < NUM_RUNNERS; ++row){
        inFile >> runners[row].name;
        for (int col = 0; col < DAYS_OF_WEEK; ++col){
            inFile >> runners[row].miles[col];
        }
    }
    inFile.close();
    return true;
}
//total calculation and average calculations
void calculateTotals(Runner runners[], int numRunners, int Days_OF_Week){
     for (int row = 0; row < numRunners; ++row){
        double sum = 0.0;
        for (int col = 0; col < DAYS_OF_WEEK; ++col){
            sum += runners[row].miles[col];
        }
        runners[row].total = sum;
        runners[row].average = sum / DAYS_OF_WEEK;

     }
}
//Data display
void displayResults(const Runner runners[], int numRunners, int Days_Of_Week){

                    
  //column names
  cout << left << setw(11) <<"Name";
  for (int col = 1; col <= DAYS_OF_WEEK; ++col){
      cout << right <<setw(7) << ("Day" + to_string(col));
  }
  cout << setw(11) << "Total" << setw(11) << "Average" << "\n";
  cout << "-----------------------------------------------------------------------------------" << endl;

  // Rows for data

  cout << fixed << setprecision(2);
  for (int row = 0; row < numRunners; ++row) {
      cout << left << setw(11) << runners[row].name;
      for (int col = 0; col < DAYS_OF_WEEK; ++col){
          cout << right << setw(7) << runners[row].miles[col];
      }
      cout << setw(11) << runners[row].total << setw(11) << runners[row].average << "\n";
      cout << "-----------------------------------------------------------------------------------" << endl;
   }
}
            