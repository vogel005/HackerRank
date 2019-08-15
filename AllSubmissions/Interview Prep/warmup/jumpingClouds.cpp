#include <bits/stdc++.h>

using namespace std;


int jumpingOnClouds(vector<int> c) {
  int jump=0; //jump count
  int end = c.size(); //end of clouds 

  int i =0;
  while(i < end)
  {
    if(i+1 >= end) //if the end has been reached
      i++;
    else if(i+2 >= end){ //if end is within 2 ranges of a jump
      if(c[i+1] == 0){
        jump++;
        i++;
      }
      else
        i++;
    }
    else{ //if the end is not within 1 or 2 ranges of a jump
      if(c[i+1] ==0 && c[i+2] ==0){ // 000, 2 range jump
        jump++;
        i+=2;
      }
      else if(c[i+1]==0 && c[i+2]==1){ //001, 1 range jump
        jump++;
        i++;
      }
      else if(c[i+1]==1 && c[i+2]==0){ //010, 2 range jump
        jump++;
        i+=2;
      }
    }
  }

  return jump;
}