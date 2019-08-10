#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

/*
PURPOSE: Finds Binomial Distribution.
DATE: 7-16-2019
*/
class binomialDistribution{
  private:
    float x; //number of success
    float n; //number of trial runs
    float p; //success of 1 trial
    float q; //failure of 1 trial

  public:
    binomialDistribution(float x, float n, float p){
      this->x=x;
      this->n=n;
      this->p=p;
      q=1-p;
    }

    int factorial(int num); //finds factorial of given number
    float calcCombin(); //combination of n,x = n!/(x!*(n-x)!)
    float calcBiDis(); //binomial distribution of n,x,p = (n x) * p^x * q^(n-x)
};

int binomialDistribution::factorial(int num) {
  return (num<2) ? 1 : num*factorial(num-1);
}

float binomialDistribution::calcCombin(){
  return factorial(n) / (factorial(x) * factorial(n-x));
}

float binomialDistribution::calcBiDis(){
  return calcCombin() * pow(p,x) * pow(q,(n-x));
}

/*
PURPOSE: Given the ratio of boy to girl births, find the proportion of families that have exactly 6 kids that have atleast 3 boys.
DATE: 7-16-2019
*/
int main() {
  float br, gr; //boy and girl ratios
  float ans=0; //cumulative probablity of 3-6 boys within the family.
  cin>>br>>gr;
  
  for(int i=3;i<=6;i++)
  {
    binomialDistribution answer(i,6,(br/(br+gr)));
    ans+=answer.calcBiDis();
  }
  //3 decimal answer
  cout<<fixed<<setprecision(3)<<ans<<endl;

  return 0;
}