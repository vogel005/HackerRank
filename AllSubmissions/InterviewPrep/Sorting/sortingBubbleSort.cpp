#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Bubble sorts vector in ascending order and counts how many swaps happened
DATE: 5-22-2019
PARAMETERS: 
* vector<int> a, an unsorted vector.
VARIABLES:
* int count, increments each time a swap happens
*/
void countSwaps(vector<int> a) {
  int count =0; 
 
  for (int i = 0; i < a.size(); i++) 
  {
    for (int j = 0; j < a.size()-i-1; j++) 
    {
      // Swap adjacent elements if they are in decreasing order
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
        count++;
      }
    }
  }

  cout << "Array is sorted in " << count << " swaps." << endl;
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a[a.size()-1] << endl;
  return;
}