#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Determines how many characters need to be deleted such that string s has no repeating letters adjacement e.q. ABABA...repeating.
DATE: 5-23-2019
PARAMETERS:
* string s, string containing A and/or B characters only.
VARIABLES:
* auto count, number of times a character was deleted in string s.
*/
int alternatingCharacters(string s) {
  auto count=0;

  for(auto i=0; i < s.size()-1; i++) //n-1 as we are comparing in pairs
  {
    if(s[i] == s[i+1]){ //if current and adjacent character are same, delete adjacement 
      s.erase(s.begin()+i+1);
      i--;
      count++;
    }
  }

  return count;
}