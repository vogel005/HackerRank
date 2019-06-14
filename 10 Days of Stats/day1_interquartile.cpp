#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


float getInterq(int n, int arr[][2]);
float findQ(vector<int> arr);

/*
PURPOSE: Fills a 2D array, Displays the interquartile range.
DATE: 6-14-2019
INPUT:
* int n; size of array.
* int arr[][2]; a 2D array where one row is a series of numbers, and the second row is the frequency of the corresponding numbers. 
OUTPUT:
* float interq; the interquartile range, displayed with 1 decimal point.
*/
int main() {
  int n;
  cin>>n;
  int arr[n][2];

  for(int i=0;i<n;i++)
    cin>>arr[i][0];

  for(int i=0;i<n;i++)
    cin>>arr[i][1];

  float interq=getInterq(n, arr);

  cout<<fixed<<setprecision(1)<<interq<<endl;
  
  return 0;
}

/*
PURPOSE: Compounds the 2D array into one vector, finds Quartile1&3, gets the difference of Q3&1 to find the interquartile range.
DATE: 6-14-2019
PARAMETERS:
* int n; size of the 2D array
* int arr[][2]; 2D array with 1st row being numbers, 2nd row being the frequency of each of 1st rows numbers.
VARIABLES:
* vector<int> fullarr; it's the 2D array compounded. as the frequency is fully added into this vector for every 1st row number. this is sorted so Q1&3 can be found.
* int size; for viewing clarity, the size of the fullarr is stored here.
* vector<int> q; is a temporary vector. initially starts as the lower half of fullarr to find Q1. but is changed into being the upper half of fullarr to find Q3.
* float q1, q3; the values of quartile 1 and 3 respectively.
* float interq; the difference of Q3 and Q1, resulting in the interquartile range.
*/
float getInterq(int n, int arr[][2]){
  vector<int> fullarr;
  
  for(int i=0;i<n;i++) //compounding arr into fullarr
    for(int j=0;j<arr[i][1];j++)
      fullarr.push_back(arr[i][0]);

  int size = fullarr.size();
  sort(fullarr.begin(), fullarr.end());
  vector<int> q(fullarr.begin(), fullarr.begin()+(size/2)); //q is lower half

  float q1=findQ(q);

  q.clear();
  //q is upper half
  if(size%2==0) //even
    copy(fullarr.begin()+(size/2), fullarr.end(), back_inserter(q));
  else //odd
    copy(fullarr.begin()+(size/2+1), fullarr.end(), back_inserter(q));

  float q3=findQ(q);

  float interq=q3-q1;

  return interq;
}

/*
PURPOSE: A generic function to find any quartile, which is done by finding the middle value of a series of numbers.
DATE: 6-14-2019
PARAMETERS:
* vector<int> arr; a series of numbers.
VARIABLES:
* float q; the middle value of a series of numbers.
* int n; for viewing clarity, the size of arr.
*/
float findQ(vector<int> arr){
  float q=0;
  int n=arr.size();

  if(n%2==0){//even
    q=arr[n/2]+arr[n/2-1];
    q/=2;
  }
  else //odd
    q=arr[n/2];

  return q;
}