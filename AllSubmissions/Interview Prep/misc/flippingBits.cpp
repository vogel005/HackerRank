#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Flips all bits, 0->1 / 1->0 respectively.
DATE: 6-6-2019
PARAMETER: long n; 32bit unsigned integer.
*/
long flippingBits(long n) {
  //an XOR boolean operation between the maximum unsigned integer value(all 1's) VS n. meaning if a bit in n is 0, it'll turn on(1^0=1). and if a bit in n is 1, it'll turn off (1^1=0).
  return (UINT_MAX)^n; 
}