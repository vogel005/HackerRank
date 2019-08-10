#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

/*
PURPOSE: Finds Poisson Distributions.
DATE CREATED: 7-19-2019
VARIABLES:
float lambda; //average mean of success
float k; //actual number of successess
*/
class Poisson{
  public:
    int Factorial(int n); //finds factorial of given number
    float P(float k, float lambda); //P(k, λ) = λ^k * e^(-λ) / k!
    float E(float lambda); //E[X^2] = λ + λ^2

};

int Poisson::Factorial(int n) {
  return (n<2) ? 1 : n*Factorial(n-1);
}

float Poisson::P(float k, float lambda){
  return (pow(lambda,k) * pow(2.71828,-lambda))/Factorial(k);
}

float Poisson::E(float lambda){
  return lambda+pow(lambda,2);
}

/*
PURPOSE: Given the means of machine A and B, finds the Poisson random variable X^2 for each machine.
DATE CREATED: 7-19-2019
*/
int main() {
  float mean_a, mean_b;
  cin>>mean_a>>mean_b;
  Poisson answer;

  //cost of car A
  cout<<fixed<<setprecision(3)<<160+40*answer.E(mean_a)<<endl;
  //cost of car B
  cout<<fixed<<setprecision(3)<<128+40*answer.E(mean_b)<<endl;
    
  return 0;
}