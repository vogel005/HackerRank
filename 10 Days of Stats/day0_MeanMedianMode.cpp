#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

/*
PURPOSE: Finds the sum of all numbers within array, then divides it by the size.
DATE: 6-7-2019
PARAMETERS:
* vector<int> arr. a series of integers.
VARIABLES:
* double mean; sum of array divided by size.
*/
double getMean(vector<int> arr) {
  double mean = 0;

  // MEAN, sums up all numbers in array
  for (int i = 0; i < arr.size(); i++)
    mean += arr[i];

  mean /= arr.size();

  return mean;
}

/*
PURPOSE: Finds the median of a given array.
DATE: 6-7-2019
PARAMETERS:
* int n; size of the array
* vector<int> arr; series of integers.
VARIABLES:
* double median; the median of an array.
*/
double getMedian(int n, vector<int> arr) {
  double median = 0;

  // sorts array so middle values are accessible
  sort(arr.begin(), arr.end());
  // even array size
  if (n % 2 == 0) {
    median = arr[n / 2] + arr[n / 2 - 1];
    median /= 2;
  }
  // odd
  else {
    median = arr[n / 2];
  }

  return median;
}

/*
PURPOSE: Finds the highest frequency number within an array. If there is a tie,
the lower value is chosen. DATE: 6-7-2019 PARAMETERS:
* int arr; a series of integers.
VARIABLES:
* int mode; the highest frequency number.
* auto count; counts the frequency of current number.
* auto max; the max count associated with long mode.
* int num; the current number being counted.
*/
int getMode(vector<int> arr) {
  sort(arr.begin(), arr.end());
  
  long mode = 0;
  auto count = 0;
  auto max = 0;
  int num;

  for (int i = 0; i < arr.size(); i++) {
    
    if (arr[i] == num) { // counting num
      count++;
    } 
    else if (count > max) { // replaces mode if num appears more often
      max = count;
      mode = num;
      num = arr[i];
      count = 1;
    } 
    else{
      num = arr[i];
      count=1;
    }
  }
    return mode;
  }

/*
PURPOSE: Finds the mean, median, and mode of a given series of integers.
DATE: 6-6-2019
INPUT:
* auto n; size of the array. auto so it can either be int or long.
* vector <int> arr; a vector array that is filled with a series of integers.
OUTPUT:
* double mean; the mean of arr. one decimal point.
* double median; the median of arr. one decimal point.
* long mode; the mode of arr.
*/
int main() {
  auto n = 0;
  cin >> n;
  vector<int> arr;
  double mean = 0;
  double median = 0;
  int mode = 0;
  long x;
  
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }

  mean = getMean(arr);
  median = getMedian(n, arr);
  mode = getMode(arr);

  // output. one decimal point
  cout << fixed << setprecision(1) << mean << endl; 
  cout << median << endl;
  cout << mode << endl;
  return 0;
}