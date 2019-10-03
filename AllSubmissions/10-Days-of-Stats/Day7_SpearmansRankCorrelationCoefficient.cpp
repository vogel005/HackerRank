#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

/*
PURPOSE: Functions generally related together via statistics.
DATE: 7-31-2019
*/
namespace mystats{
  /*
  PURPOSE: Finding ranking of a series of numbers. Smallest number is 1, and increments from there.
  VARIABLES:
  arr; (PARAMETER) A given series of numbers.
  sorted; arr, but sorted least to greatest.
  r; (RETURN) Rankings that correspond with the numbers of arr. 
  */
  std::vector<int> Rank(std::vector<float> &arr){
    std::vector<float> sorted=arr;
    std::vector<int> r(arr.size()); 
    
    std::sort(sorted.begin(), sorted.end());

    for(int i=0;i<arr.size();i++){
      auto itr= std::find(sorted.begin(), sorted.end(), arr[i]);
      r[i]= std::distance(sorted.begin(), itr)+1;
    }

    return r;
  }
  /*
  PURPOSE: Spearman's Rank Correlation Coefficient. X and Y must be same size and have all unique values.
  VARIABLES:
  X and Y; (PARAMETERS) A series of unique values.
  n; Size of X and Y.
  rx and ry; The ranking of X and Y respectively.
  d; The difference of rx and ry.
  */
  float SRCC(std::vector<float> X, std::vector<float> Y){
    float d=0;
    int n= X.size();
    std::vector<int> rx=Rank(X);
    std::vector<int> ry=Rank(Y);
    
    for(int i=0;i<n;i++)
      d+=pow(rx[i]-ry[i], 2);

    return 1 - (6*d)/(n*(pow(n,2)-1));
  }
};


int main() {
  //n
  int n;
  std::cin>>n;
  //X
  std::vector<float> X(n);
  for(int i=0;i<n;i++)
    std::cin>>X[i];
  //Y
  std::vector<float> Y(n);
  for(int i=0;i<n;i++)
    std::cin>>Y[i];

  std::cout<<std::fixed<<std::setprecision(3)<<mystats::SRCC(X, Y);

  return 0;
}