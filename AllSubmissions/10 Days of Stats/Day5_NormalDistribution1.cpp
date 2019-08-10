#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

/*
PURPOSE: General mathematical equations. 
DATE: 7-22-2019
*/
namespace math{
  //Cummulative Distribution Function for Normal Distribution, denoted by phi.
  float NormalPhi(float x, float u, float o){
    return 0.5 * (1 + std::erf((x - u)/(o*sqrt(2))));
  }

};

/*
PURPOSE: Given the mean and standard deviation, the probability is found if a car can be repaired within 19.5 hours or between 20-22hours using Normal Distribution.
DATE: 7-22-2019
*/
int main() {
  float u, o; //mean(20 hours) and standard deviation (2hours) 
  std::cin>>u>>o;
  float q1; //19.5 hours
  std::cin>>q1;
  float q2_low, q2_high; //20 and 22 hours
  std::cin>>q2_low>>q2_high;

  std::cout<<std::fixed<<std::setprecision(3)<<math::NormalPhi(q1, u, o)<<std::endl;

  std::cout<<std::fixed<<std::setprecision(3)<<math::NormalPhi(q2_high, u, o) - math::NormalPhi(q2_low, u, o)<<std::endl;

  return 0;
}