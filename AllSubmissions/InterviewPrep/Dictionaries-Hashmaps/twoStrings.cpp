#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Sees if at most 1 character is shared between the strings.
DATE: 5-21-2019
PARAMETERS:
* s1, first word.
* s2, second word.
VARIABLES:
* yn, YES or NO depending on if the character is found.
* sSet, contains s1 such that we can compare it with the second string.
*/
string twoStrings(string s1, string s2) {
  string yn = "NO"; 
  unordered_set<char> sSet;

  for(auto const& chara: s1)
    sSet.insert(chara);

  for(auto const &chara: s2) 
  {
    if(sSet.count(chara) > 0){ //atleast 1 shared character found.
      yn = "YES";
      return yn;
    }
  }

  return yn;
}
