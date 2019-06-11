#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a;
    long b;
    char c;
    float d;
    double e;

    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);

    printf("%d %c", a, '\n');
    printf("%ld %c", b, '\n');
    printf("%c %c", c, '\n');
    printf("%f %c", d, '\n');
    printf("%lf %c", e, '\n');

    return 0;
}