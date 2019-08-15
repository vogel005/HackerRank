#include <bits/stdc++.h>

using namespace std;



  /*
  PURPOSE: Converts decimal number into binary, then counts what the longest consecutive 1 count is.
  DATE: 6-18-2019
  INPUT:
  * int n; a number to be converted into binary.
  VARIABLES:
  * int r; remainder after dividing n by 2, used to find the binary number
  * string b; a binary string. 
  * int c; counts consecutive 1's in the binary string.
  * int max; the maximum count found.
  */

int main()
{
  int n;
  cin >> n;

  int r;
  string b; 
  int c=0; 
  int max=0;

  while(n>0) //binary conversion
  {
    r=n%2;
    n/=2;
    b.push_back('0'+r);
  }
  reverse(b.begin(), b.end());

  for(int i=0;i<b.length();i++) //consecutive 1 counting
  {
    if(b[i]=='1')
      c++;
    else
      c=0;
    
    if(c>max)
      max=c;
  }
  
  cout<<max<<endl;
  return 0;
}