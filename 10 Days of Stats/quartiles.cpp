#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int quart1(vector<int> arr);
int quart2(int n, int arr[]);
int quart3(vector<int> arr);
void getQ(int n, int arr[]);

/*
PURPOSE: Finds the first, second and third quartiles and displays them.
DATE: 6-11-2019
INPUT:
* int n; size of array.
* int arr[]; a series of integers.
OUTPUT:
* getQ(n, arr); displays the results of functions q1,q2,q3.
*/
int main() {
  int n;
  cin >> n; 
  int arr[n];

  for(int i=0; i<n; i++)
    cin >> arr[i];
  
  getQ(n, arr);
  

  
  return 0;
}

/*
PURPOSE:
DATE: 6-11-2019
PARAMETERS:
* int n; the size of the full array.
* int arr[]; the full array of numbers.
VARIABLES:
* int q1,q2,q3; the results of functions q1,q2,q3.
* vector<int> arr2; a dynamic vector that is modified based upon computing methods of quartiles.
*/
void getQ(int n, int arr[]){
  int q1, q2, q3 =0;
  vector<int> arr2;
  sort(arr, arr+n);

  q2=quart2(n, arr);
  
  if(n%2==0) //even
    copy(arr, arr+n/2, back_inserter(arr2));
  else //odd
    copy(arr, arr+n/2, back_inserter(arr2));

  q1=quart1(arr2);

  arr2.clear();

  if(n%2==0) //even
    copy(arr+n/2, arr+n, back_inserter(arr2));
  else //odd
    copy(arr+n/2+1, arr+n, back_inserter(arr2));

  q3=quart3(arr2);

  cout << q1 << endl << q2 << endl << q3 << endl;

  return;
}

/*
PURPOSE: Finds the median of a given series of numbers.
DATE: 6-11-2019
PARAMETERS:
* int n; the size of the full array.
* int arr[]; the full array of numbers.
VARIABLES:
* int median; the middle value of the array.
*/
int quart2(int n, int arr[]){
  int median=0;

  if(n%2==0){ //even
    median=arr[n/2]+arr[n/2-1];
    median/=2;
  }
  else //odd
    median=arr[n/2]; 

  return median;
}

/*
PURPOSE: Finds the first quartile.
DATE: 6-11-2019
PARAMETERS:
* vector<int> arr; an array that is allocated with the lower half of a series of numbers.
VARIABLES:
* int ln; the size of the lower half of a series of numbers.
*/
int quart1(vector<int> arr){
  int q1=0;
  int ln=arr.size();
  
  if(ln%2==0){//even
    q1=arr[ln/2]+arr[ln/2-1];
    q1/=2;
  }
  else
    q1=arr[ln/2];

  return q1;
}

/*
PURPOSE: Finds the third quartile.
DATE: 6-11-2019
PARAMETERS:
* vector<int> arr; an array that is allocated with the lower half of a series of
numbers. VARIABLES:
* int hn; the size of the higher half of a series of numbers.
*/
int quart3(vector<int> arr) {
  int q3 = 0;
  int hn = arr.size();
  
  if (hn%2==0) { // even
    q3=arr[hn/2]+arr[hn/2-1];
    q3/=2;
  } else
    q3=arr[hn/2];

  return q3;
}