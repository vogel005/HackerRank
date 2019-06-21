#include <iostream>
#include <iomanip>
using namespace std;

float getWM(int n, int arr[], int w[]);

/*
PURPOSE: Finds the weighted mean of a series of integers their accompanying weight.
DATE: 6-13-2019
INPUT:
* int n; size of array.
* int arr[]; series of integers.
* int weight[]; the assigned weight for every corresponding number in arr[].
OUTPUT:
* float wm; the weighted mean of arr[] & weight[], display at 1 decimal point.
*/
int main() {
  int n;
  cin>>n;
  int arr[n];
  int weight[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

  for(int i=0;i<n;i++)
    cin>>weight[i];

  float wm = getWM(n, arr, weight);

  cout<<fixed<<setprecision(1)<<wm<<endl;
  return 0;
}

/*
PURPOSE: Calculates the weighted mean of the given array.
DATE: 6-13-2019
PARAMETERS:
* int n; size of array.
* int arr[]; series of integers.
* int w[]; the weight of each integer in arr[].
VARIABLES:
* float wm; the weighted mean of arr[]
* float wsum; the sum of w[].
*/
float getWM(int n, int arr[], int w[]){
  float wm=0;
  float wsum=0;

  for (int i = 0; i < n; i++){
    wm += arr[i] * w[i];
    wsum+=w[i];
  }

  wm/=wsum;

  return wm;
}
