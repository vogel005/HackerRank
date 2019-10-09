#include <bits/stdc++.h>

using namespace std;

//returns factorial of n
//DATE: 6-17-2019
int factorial(int n) {
  return (n==0) ? 1 : n*factorial(n-1);
}