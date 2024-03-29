#include <bits/stdc++.h>
#include <climits>  
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
  int currSum; //current sum of hourglass
  int maxSum=INT_MIN; //max sum of any of the hourglasses, initialized to lowest int value

  //the Hourglass shape can only traverse 4 times through the rows, and 4 through columns when its 6x6. 
  for(int i=0; i < 4; i++) //traversal of rows
  {
    for(int j=0; j<4; j++) //traversal of columns 
      {
       currSum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]; //hourglass shape 

       if(currSum > maxSum)
          maxSum = currSum; 
      }
  }

  return maxSum;
}