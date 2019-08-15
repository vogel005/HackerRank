#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Returns the maximum amount of toys that can be bought while shopping with a certain budget 
DATE: 5-22-2019
PARAMETERS:
* vector<int> prices, list of prices.
* int k, budget that can be spent
VARIABLES:
* int maxToys, how many toys can be bought
* int total, total price of how many toys can be bought
*/
int maximumToys(vector<int> prices, int k) {
  int maxToys =0; 
  int total=0;

  sort(prices.begin(), prices.end());

  for(int i=0; i < prices.size(); i++)
  {
    if(total + prices[i] <= k){
      total +=prices[i];
      maxToys++;
    }
    else 
      i=prices.size(); //ends for loop after the price total goes over budget 
  }

  return maxToys;
}