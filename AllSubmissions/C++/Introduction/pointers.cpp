#include <stdio.h>
#include <cstdlib>

void update(int *a,int *b) { 
  int c, d;
  c = *a+*b;
  d = abs(*a-*b);

  *a = c;
  *b = d;
  return;
}