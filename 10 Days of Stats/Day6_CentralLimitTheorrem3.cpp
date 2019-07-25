#include <cmath>
#include <iostream>
#include <iomanip>

/*
PURPOSE: Finds the sample mean of the interval percentage given.
DATE: 7-25-2019
*/
int main() {
  float n, u, o, a_b, z;
  //population value
  std::cin>>n;
  //mean and standard deviation
  std::cin>>u>>o;
  //percentage of sample between A and B, and it's equivalent Z-score.
  std::cin>>a_b>>z;

  //using Z score to find the Margin of Error for the confidence interval
  float margin_of_error= z * o/sqrt(n);

  //A value
  std::cout<<std::fixed<<std::setprecision(2)<<u - margin_of_error<<std::endl;
  //B value
  std::cout<<u + margin_of_error<<std::endl;

  return 0;
}