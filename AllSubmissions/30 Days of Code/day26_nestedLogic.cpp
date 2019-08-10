#include <iostream>
using namespace std;

int fine(int arr[][2]);


int main() {
  int arr[3][2];
  cin>>arr[0][0]>>arr[1][0]>>arr[2][0]; //returned book on day, month, year
  cin>>arr[0][1]>>arr[1][1]>>arr[2][1]; //due date for book day, month, year

  cout<<fine(arr)<<endl;

  return 0;
}

/*
PURPOSE: Finds if a returned book is past its due date or not and the appropriate fine amount.
DATE: 7-9-2019
PARAMETERS:
int arr[][2]; a 2D array that contains the returned book's day, month, year on 1st layer, and due date for the book's day, month, year on 2nd layer.
VARIABLES:
int amount; size of fine depending on what day it was returned.
RETURN:
* if returned before or on same day as due date: 0 fine
* if returned after month of due date: 500 * (months late)
* if returned after day of due date, but within same month: 15 * (days late) 
* if returned after the year of due date: 10,000 
*/
int fine(int arr[][2]){
  //year
  if(arr[2][0]<arr[2][1]) //return year < due date year
    return 0;
  else if(arr[2][0]>arr[2][1]) 
    return 10000;
  //month
  if(arr[1][0]<arr[1][1]) //return month < due date month
    return 0;
  else if(arr[1][0]>arr[1][1])
    return (500 * (arr[1][0]-arr[1][1])); //500 * (months late)
  
  //day
  int amount;
  if(arr[1][0]==arr[1][1]){ 
    if(arr[0][0]<=arr[0][1]) //return day is <= due date day
      amount=0;
    else
      amount=15 * (arr[0][0]-arr[0][1]); //15 * (days late)
  }

  return amount;
}