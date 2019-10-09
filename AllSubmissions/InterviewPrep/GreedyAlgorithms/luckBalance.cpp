#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Adds up all unimportant + k amount of important contests to a returning luck value. Removes from sum if theres more important contests than k.
DATE: 5-28-2019
PARAMETERS: 
* int k, the amount of important contests that Lena can lose
* vector<vector<int>> contests, contains a Luck value at j=0, and an importance level of 1 or 0 at j=1. 
VARIABLES:
* int count, is the luck value sum of contests.
* vector<int> important, contains all the important contest values, so that they can be sorted and added/subtracted correctly.
*/
int luckBalance(int k, vector<vector<int>> contests) {
  int count=0;
  vector<int> important; 

  for(int i = 0; i < contests.size(); i++) {
    if (contests[i][1] == 1)
      important.push_back(contests[i][0]);
    else
      count += contests[i][0];
  }

  sort(important.begin(), important.end(), greater<int>()); //add the higher contest values first

  for(int i=0; i < important.size(); i++)
  {
    if(i>=k) //if theres more important tasks than k
      count-=important[i];
    else
      count+=important[i];
  }
  return count;
}