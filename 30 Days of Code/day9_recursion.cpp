#include <bits/stdc++.h>

using namespace std;

//returns factorial of n
//DATE: 6-17-2019
int factorial(int n) {
  return (n==0) ? 1 : n*factorial(n-1);
}

int main() //hackerrank code
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = factorial(n);

    fout << result << "\n";

    fout.close();

    return 0;
}