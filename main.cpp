// Created by Shaurya Srivastav
// Date: January 27th, 2023
// Purpose: to calculate a set of outputs given a particular function

#include <iostream>
#include <math.h>
using namespace std;

void rightEndPointArea(int modifiedInput[], int size, int width) {
  int totalArea = 0;
  int individualHeightOfRectangle;
  for (int i = 1; i < size; i++) {
    individualHeightOfRectangle = (modifiedInput[i]) * width;
    totalArea = totalArea + individualHeightOfRectangle;
  }

  cout << "The total Area under the curve using the right-endpoint method is: "
       << totalArea << "\n";
}

void leftEndPointArea(int modifiedInput[], int size, int width) {
  int totalArea = 0;
  int individualHeightOfRectangle;
  for (int i = 0; i < size; i++) {
    individualHeightOfRectangle = (modifiedInput[i]) * width;
    totalArea = totalArea + individualHeightOfRectangle;
  }

  cout << "The total Area under the curve using the left-endpoint method is: "
       << totalArea << "\n";
}

void functionOutput(int input[], int size,
                    int width) { // calculates outputs of the function and sends
                                 // them to the rest

  int updatedDataPoints[size];

  for (int i = 0; i < size; i++) {
    int updatedValues =
        (36 -
         (pow(input[i], 2))); // change this variable to reflect your function
    updatedDataPoints[i] = updatedValues;
  }

  cout << "\nThe function has the following outputs: \n";

  for (int i = 0; i < size; i++) {
    cout << updatedDataPoints[i] << "\n";
  }

  cout << "\n";

  leftEndPointArea(updatedDataPoints, size, width);
  rightEndPointArea(updatedDataPoints, size, width);
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

  int width;

  cout << "Enter rectangle width: ";
  cin >> width;

  cout << "\n";

  functionOutput(dataValues, numDataPoints, width);

  return 0;
}