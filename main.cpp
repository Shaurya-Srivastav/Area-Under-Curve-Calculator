// Created by Shaurya Srivastav
// Date: September 13, 2023
// Purpose: Calculate integrals and graph mathematical functions

#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include "matplotlibcpp.h" // Requires matplotlib-cpp for plotting (https://github.com/lava/matplotlib-cpp)

namespace plt = matplotlibcpp;

const int kMaxDataPoints = 100;

int RightEndPointArea(const int modified_input[], int size, int width) {
  int total_area = 0;
  for (int i = 1; i < size; i++) {
    int individual_height = modified_input[i] * width;
    total_area += individual_height;
  }
  return total_area;
}

int LeftEndPointArea(const int modified_input[], int size, int width) {
  int total_area = 0;
  for (int i = 0; i < size; i++) {
    int individual_height = modified_input[i] * width;
    total_area += individual_height;
  }
  return total_area;
}

// Function to calculate the integral using trapezoidal rule
double TrapezoidalIntegral(std::function<double(double)> func, double a, double b, int num_intervals) {
  double h = (b - a) / num_intervals;
  double integral = 0.5 * (func(a) + func(b));

  for (int i = 1; i < num_intervals; i++) {
    double x = a + i * h;
    integral += func(x);
  }

  return h * integral;
}

// Function to parse a mathematical expression and return a lambda function
std::function<double(double)> ParseExpression(const std::string& expression) {
  std::string parsed_expression = "[](double x) { return " + expression + "; }";
  std::function<double(double)> func = std::function<double(double)>(eval(parsed_expression));
  return func;
}

int main() {
  int num_data_points;
  cout << "Enter the number of x-values you need: ";
  cin >> num_data_points;

  if (num_data_points > kMaxDataPoints) {
    cout << "Error: Number of data points exceeds the maximum allowed." << endl;
    return 1;
  }

  int data_values[kMaxDataPoints];

  for (int i = 0; i < num_data_points; i++) {
    cout << "Input data value " << (i + 1) << ": ";
    cin >> data_values[i];
  }

  int width;

  cout << "Enter rectangle width: ";
  cin >> width;

  cout << "\n";

  int left_area = LeftEndPointArea(data_values, num_data_points, width);
  int right_area = RightEndPointArea(data_values, num_data_points, width);

  cout << "The total Area under the curve using the left-endpoint method is: "
       << left_area << "\n";
  cout << "The total Area under the curve using the right-endpoint method is: "
       << right_area << "\n";

  // Input and integrate a function
  double a, b;
  int num_intervals;
  std::string user_expression;

  cout << "Enter the integration interval [a, b]: ";
  cin >> a >> b;
  cout << "Enter the number of intervals for integration: ";
  cin >> num_intervals;

  cout << "Enter a mathematical expression (e.g., 'x^2 + sin(x)'): ";
  cin.ignore();
  std::getline(cin, user_expression);

  // Parse the user's mathematical expression
  auto func = ParseExpression(user_expression);

  double integral = TrapezoidalIntegral(func, a, b, num_intervals);
  cout << "The integral of the function within the interval [" << a << ", " << b << "] is: " << integral << "\n";

  // Plot the user's function
  std::vector<double> x_values, y_values;
  double step = (b - a) / 100; // 100 points for the graph
  for (double x = a; x <= b; x += step) {
    x_values.push_back(x);
    y_values.push_back(func(x));
  }

  plt::plot(x_values, y_values);
  plt::title("Graph of the Function");
  plt::show();

  return 0;
}
