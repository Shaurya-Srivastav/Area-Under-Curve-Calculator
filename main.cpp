// Created by Shaurya Srivastav
// Date: January 27th, 2023
// Purpose: to calculate a set of outputs given a particular function

#include <iostream>
#include <math.h>
using namespace std;

void functionOutput(int input[], int size) {

  int updatedDataPoints[size];

  for (int i = 0; i < size; i++) {
    int updatedValues = (36 - (pow(input[i], 2))); //change this variable to reflect your function
    updatedDataPoints[i] = updatedValues;
  }

  cout << "\nThe function has the following outputs: \n";

  for (int i = 0; i < size; i++) {
     cout << updatedDataPoints[i] << "\n";
  }
}

int main() {
  int numDataPoints;
  cout << "Enter the amount of x-values you need: ";
  cin >> numDataPoints;

  int dataValues[numDataPoints];

  for (int i = 0; i < numDataPoints; i++) {
    cout << "Input data value " << (i + 1) << ": ";
    cin >> dataValues[i];
  }

  functionOutput(dataValues, numDataPoints);

  return 0;
}