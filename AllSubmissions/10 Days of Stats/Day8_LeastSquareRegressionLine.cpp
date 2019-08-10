#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

/*
PURPOSE: Mathematical functions generally related together via statistics.
DATE: 8-1-2019
*/
namespace mystats{
  //Mean, u
  template <typename T>
  float Mean(std::vector<T> arr){ 
    float u=0;

    for(int i=0;i<arr.size();i++)
      u+=arr[i];

    return u/=arr.size();
  }
  //Variance, o^2
  template <typename T>
  float Variance(std::vector<T> arr){ 
    float o2=0;
    float u=Mean(arr);

    for(int i=0;i<arr.size();i++)
      o2+=pow(arr[i]-u,2);

    return o2/=arr.size();
  }
  //Standard Distribution, o
  template <typename T>
  float SD(std::vector<T> arr){
    return sqrt(Variance(arr));
  }

  //Covariance, cov
  template <typename T>
  float Cov(std::vector<T> X, std::vector<T> Y){
    int n=X.size(); //X and Y must have same size.
    float ux=Mean(X);
    float uy=Mean(Y);
    float sum=0;

    for(int i=0;i<n;i++)
      sum+=(X[i]-ux)*(Y[i]-uy);

    return sum/n;
  }
  //Pearson Correlation Coefficient, p
  template <typename T>
  float PCC(std::vector<T> X, std::vector<T> Y){
    float ox=SD(X);
    float oy=SD(Y);

    return Cov(X,Y)/(ox*oy);
  }

  //Regression Line equation
  template <typename T>
  float RL(std::vector<T> X, std::vector<T> Y, T x_val){

    float b= PCC(X,Y)*SD(Y)/SD(X);
    float a= Mean(Y)-b*Mean(X);

    return a+b*x_val;
  }
};

/*
PURPOSE: Using 5 students math test score (X) and stats class grade (Y), the class grade is found given if a test score is 80. 
DATE: 8-1-2019 
*/
int main() {
  std::vector<int> X, Y;

  for(int i=0;i<5;i++)
  {
    int test,grade;
    std::cin>>test>>grade;
    X.push_back(test);
    Y.push_back(grade);
  }

  std::cout<<std::fixed<<std::setprecision(3)<<mystats::RL(X,Y, 80);

  return 0;
}