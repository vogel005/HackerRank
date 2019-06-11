#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d){
  int currentMax =a;

  if(currentMax < b)
    currentMax = b;

  if(currentMax < c)
    currentMax = c;

  if(currentMax < d)
    currentMax = d;

  return currentMax;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}