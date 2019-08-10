#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

/*
PURPOSE: General utility mathematical equations.
DATE: 7-30-2019
*/
namespace mymath{
  //Mean, u
  float Mean(std::vector<float> arr){ 
    float u=0;

    for(int i=0;i<arr.size();i++)
      u+=arr[i];

    return u/=arr.size();
  }
  //Variance, o^2
  float Variance(std::vector<float> arr){ 
    float o2=0;
    float u=Mean(arr);

    for(int i=0;i<arr.size();i++)
      o2+=pow(arr[i]-u,2);

    return o2/=arr.size();
  }
  //Standard Distribution, o
  float SD(std::vector<float> arr){
    return sqrt(Variance(arr));
  }

  //Covariance, cov
  float Cov(std::vector<float> X, std::vector<float> Y){
    float n=X.size(); //X and Y must have same size.
    float ux=Mean(X);
    float uy=Mean(Y);
    float sum=0;

    for(int i=0;i<n;i++)
      sum+=(X[i]-ux)*(Y[i]-uy);

    return sum/n;
  }
  //Pearson Correlation Coefficient, p
  float PCC(std::vector<float> X, std::vector<float> Y){
    float ox=SD(X);
    float oy=SD(Y);

    return Cov(X,Y)/(ox*oy);
  }
};

/*
PURPOSE: Given two series of numbers with the same size, X and Y, the Pearson Correlation Coeifficient is found.
DATE: 7-30-2019
*/
int main() {
  int n;
  //n
  std::cin>>n;
  //X
  std::vector<float> X(n);
  for(int i=0;i<n;i++)
    std::cin>>X[i];
  //Y
  std::vector<float> Y(n);
  for(int i=0;i<n;i++)
    std::cin>>Y[i];

  
  std::cout<<std::fixed<<std::setprecision(3)<<mymath::PCC(X, Y);

  return 0;
}
