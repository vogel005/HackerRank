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

int main() { //hackerrank code
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
