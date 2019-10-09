#include <bits/stdc++.h>

using namespace std;

int simpleArraySum(vector<int> ar) {

int sum = 0;

for(int i=0; i < ar.size(); i++)
  sum += ar[i];


return sum;
}