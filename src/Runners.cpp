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

bool readFile(const string& filename, Runner runners[], int numRunners[], int days_of_week){
    ifstream inFile(filename);
    if (!inFile){
        return false;
    }

    for(int row = 0; row < numRunners; ++row){
        inFile >> runners[row].name;
        for (int col = 0; col < days_of_week; ++col){
            inFile >> runners[row].miles[col];
        }
    }
    inFile.close();
    return true;
}
//total calculation and average calculations
void calculateTotals(Runner runners[], int numRunners, int days_of_week){
     for (int row = 0; row < numRunners; ++row){
        double sum = 0.0;
        for (int col = 0; col < days_of_week; ++col){
            sum += runners[row].miles[col];
        }
        runners[row].total = sum;
        runners[row].average = sum / days_of_week;

     }
}
//Data display
void displayResults(const Runner runners[], int numRunners, int days_of_week){

                    
  //column names
  cout << left << setw(11) <<"Name";
  for (int col = 1; col <= days_of_week; ++col){
      cout << right <<setw(7) << ("Day" + to_string(col));
  }
  cout << setw(11) << "Total" << setw(11) << "Average" << "\n";
  cout << "-----------------------------------------------------------------------------------" << endl;

  // Rows for data

  cout << fixed << setprecision(2);
  for (int row = 0; row < numRunners; ++row) {
      cout << left << setw(11) << runners[row].name;
      for (int col = 0; col < days_of_week; ++col){
          cout << right << setw(7) << runners[row].miles[col];
      }
      cout << setw(11) << runners[row].total << setw(11) << runners[row].average << "\n";
      cout << "-----------------------------------------------------------------------------------" << endl;
   }
}
            