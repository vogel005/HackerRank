#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; //index amount
    cin >> n; //reads index amount

    int arr[n]; //declares array

    for(int i=0; i < n; i++) //array input
    {
      cin >> arr[i];
    }

    for(int i = (n-1); i >= 0; i--) //displaying array in reverse
    {
      cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}