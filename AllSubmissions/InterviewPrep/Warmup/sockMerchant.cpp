#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector<int> ar) {
  int pair =0; //amount of pairs

  sort(ar.begin(), ar.end()); //sorting the sock values from lowest to highest values. meaning duplicate values will be next to each other.

  for(int i=0; i<n-1; i++)
  {
    if(ar[i] == ar[i+1]){ 
      pair++;
      i++; //increment i to skip the pair counted
    }
  }
  
  return pair; 
}