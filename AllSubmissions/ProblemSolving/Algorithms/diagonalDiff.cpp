#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
  int d1 =0;
  int d2 =0;

  for(int i=0; i < arr.size(); i++)
  {
    
    for(int j=0; j < arr.size(); j++)
    {
      //first diagnol
      if (i == j)
        d1 += arr[i][j];

      //second diagnol
      if(i + j  == arr.size()-1)
        d2 += arr[i][j];
    }
}

return abs(d1 - d2);
}