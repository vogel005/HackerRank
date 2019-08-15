#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s) {
  int valleys =0; //counts valleys
  int hike =0; //counts the traversal of the steps  

  int i =0;
  while(i < n)
  {
    if(s[i] == 'U')
      hike++;
    else if(s[i]=='D') 
      hike--;

    if(hike == 0 && s[i] == 'U') //if the step is at sea level and the prev step was hiking up, meaning its a valley.
      valleys++; 

    i++;
  }

  return valleys;
}