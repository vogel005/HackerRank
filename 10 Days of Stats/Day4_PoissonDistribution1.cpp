#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

/*
PURPOSE: Finds Poisson Distributions.
DATE: 7-19-2019
*/
class Poisson{
  private:
    float lambda; //average mean of success
    float k; //actual number of successess
    float e=2.71828; //euler's number

  public:
    Poisson(float k, float lambda){
      this->k=k;
      this->lambda=lambda;
    }

    int Factorial(int n); //finds factorial of given number
    float P(); //P(k, λ) = λ^k * e^(-λ) / k!
    float E(); //E[X^2] = λ + λ^2
};

int Poisson::Factorial(int n) {
  return (n<2) ? 1 : n*Factorial(n-1);
}

float Poisson::P(){
  return (pow(lambda,k) * pow(e,-lambda))/Factorial(k);
}

float Poisson::E(){
  return lambda+pow(lambda,2);
}

/*
PURPOSE: Given the mean and a value, finds Poisson's distribution probablity.
DATE: 7-19-2019
*/
int main() {
  float mean, value;
  cin>>mean>>value;

  Poisson answer(value,mean);

  cout<<fixed<<setprecision(3)<<answer.P()<<endl;

  return 0;
}