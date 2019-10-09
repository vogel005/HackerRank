#include <bits/stdc++.h>

using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
  vector<int> shift(a.size()); //will hold the newly shifted array

  int i=0; //location for a array
  int j=a.size()-d; //new starting position for the shifted array, n-d
  while(i < a.size())
  {
    shift[j] = a[i]; 


    if(j<shift.size()-1){ 
      j++;
    } else { // once shifted position reaches the end of array, loop back to start
      j=0;
    }
    i++;
  }

  return shift;
}