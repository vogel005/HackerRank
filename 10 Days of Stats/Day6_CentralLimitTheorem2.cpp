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
PURPOSE: Finding the probablity that 100 students can successfully purchase a remaining 250 tickets.
DATE: 7-24-2019
*/
int main() {
  float x, n, u, o;
  //tickets remaining
  std::cin>>x;
  //number of students
  std::cin>>n;
  //mean
  std::cin>>u;
  //standard deviation
  std::cin>>o;

  //Central Limit Theorem
  float u_prime=n*u;
  float o_prime=sqrt(n)*o;

  std::cout<<std::fixed<<std::setprecision(4)<<math::CDF(x, u_prime, o_prime)<<std::endl;

  return 0;
}