#include <bits/stdc++.h>

using namespace std;


/*
PURPOSE: Finds the minimum absolute difference between all pairs
DATE: 5-24-2019
PARAMETERS:
* vector<int> arr, filled with positive and negative integers
VARIABLES:
* int min, minimum absolute difference 
* int diff, temporary value holding |i-j|
*/
int minimumAbsoluteDifference(vector<int> arr) {
  int min;

  sort(arr.begin(), arr.end()); //sorted, so it can be compared in consecutive pairs  

  for(int i=0; i < arr.size()-1; i++) 
  {
    int diff = abs(arr[i]-arr[i+1]);

    if(i == 0) //baseline min is the first value
      min = diff;
    else if(diff < min)
      min = diff;
  }

  return min;
}