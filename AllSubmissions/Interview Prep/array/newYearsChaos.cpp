#include <bits/stdc++.h>

using namespace std;

void minimumBribes(vector<int> q) {
  int minBri=0; //minimum number of bribes needed

  for(int i = q.size()-1; i >= 0; i--) 
  {
    if(q[i] - (i+1) > 2) { // ticket number - position > 2 swaps. as people can only swap twice.
      cout << "Too chaotic" << endl;
      return;
    }
    for(int j = max(q[i]-2, 0); j < i; j++) // ticket value array position -1 OR 0 if its a ticket of 1, goes to current i position
      if(q[j] > q[i]) //compares current i ticket with j ticket 
        minBri++;
  }

  cout << minBri << endl; 
  return;
}