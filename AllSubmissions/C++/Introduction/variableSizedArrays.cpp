#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n; //number of variable arrays
  int q; //number of queries 
  int k; //size of an indexed array
  int d; //data for the arrays 
  int x, y; //coordinates for queries
  cin >> n >> q; 

  vector<int> a[n]; //array of vectors, as Variable Sized Arrays are not supported by C++ 

  //fill the array of vectors  
  for(int i =0; i < n; i++)
  {
    cin >> k;

      for(int j=0; j<k; j++)
      {
        cin >>d; 
        a[i].push_back(d);
      }
  }

  //read the queries, output the specified input
  while(q--)
  {
    cin >> x >> y;
    cout << a[x][y] << endl;
  }
  
  return 0;
}