#include <bits/stdc++.h>

using namespace std;

vector<int> reverseArray(vector<int> a) {
  vector<int> rev(a.size()); //reverse 
  int i, j =0; //incrementation

  i = a.size()-1; //the locations of a array backwards

  while(j < rev.size())
  {
    rev[j] = a[i]; //reverse order of array
    i--;
    j++;
  }

  return rev;
}