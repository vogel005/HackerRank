#include <iostream>

using namespace std;

/*
PURPOSE: Finds the n^th element in the fibonacci sequence. 
DATE: 6-5-2019
PARAMETERS:
* int n; the given number.
*/
int fibonacci(int n){
  return (n < 2) ? n : fibonacci(n-1) + fibonacci(n-2);
}