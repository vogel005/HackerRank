#include <cmath>
#include <iostream>
#include <iomanip>

/*
PURPOSE: General mathematical equations. 
DATE CREATED: 7-22-2019
LAST MODIFIED: 7-23-2019
*/
namespace math{
  //Cummulative Distribution Function for Normal Distribution, denoted by phi.
  float CDF(float x, float u, float o){
    return 0.5 * (1 + std::erf((x - u)/(o*sqrt(2))));
  }

};


/*
PURPOSE: Using a mean and standard deviation from a pool of students, it is found what percentage had more than an 80%, greater than and equal to 60%, and less than 60% on their grade.
DATE: 7-23-2019
*/
int main() {
  float u, o; //mean of 70, standard deviation of 10
  std::cin>>u>>o;
  float x, y; //80%, 60% grade
  std::cin>>x>>y;

  // grade>80
  std::cout<<std::fixed<<std::setprecision(2)<<100-math::CDF(x, u, o)*100<<std::endl;
  // grade>=60
  std::cout<<std::fixed<<std::setprecision(2)<<100-math::CDF(y, u, o)*100<<std::endl;
  // grade<60
  std::cout<<std::fixed<<std::setprecision(2)<<math::CDF(y, u, o)*100<<std::endl;

     
  return 0;
}