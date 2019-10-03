#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long aVeryBigSum(vector<long> ar) {
  long sum = 0;

  for(int i =0; i < ar.size(); i++)
    sum += ar[i];
    
  return sum;
}