#include <iostream>
#include <cmath>
using namespace std;

bool primeCheck(int n);

int main() {
  int n; //array size
  cin>>n;
  int arr[n]; //array of n numbers
  for(int i=0;i<n;i++)
    cin>>arr[i];

  for(int i=0;i<n;i++)
  {
    if(primeCheck(arr[i]))
      cout<<"Prime"<<endl;
    else
      cout<<"Not prime"<<endl;
  }

  return 0;
}

/*
PURPOSE: Checks if a given number is prime or not.
DATE: 7-8-2019
PARAMETERS: 
* int n; a number that will be checked to see if its a prime number. 
VARIABLES:
* int sr; the square root of n. used to see if n is divisible any number between 2 and sr.
RETURN:
false; if number is not prime.
true; if number is prime.
*/
bool primeCheck(int n){
  if(n<=1) //special case: less than or equal to 1 is not prime
    return false;

  int sr= sqrt(n);

  //if n is divisible by any number between 2 and it's square root, then its not prime. 
  for(int i=2;i<=sr;i++)
    if(n%i==0)
      return false;

  return true;
}