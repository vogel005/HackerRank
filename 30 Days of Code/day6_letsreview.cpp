#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
PURPOSE: Prints it's even and odd indexed elements in seperate strings.
DATE: 6-12-2019
INPUT:
* int n; how many strings will be inputted.
* string s; a string being read.
VARIABLES:
* string even, odd; even/odd indexed characters placed into their respective strings.
*/
int main() {
  int n=0;
  string s;
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    string even, odd;
    for(int j=0;j<s.length();j++){
      if(j%2==0 || j==0) //even
        even.push_back(s[j]);
      else //odd
        odd.push_back(s[j]);
    }
    cout<<even<<" "<<odd<<endl;
  }
  return 0;
}