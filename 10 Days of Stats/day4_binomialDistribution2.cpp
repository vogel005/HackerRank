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
PURPOSE: Given the defective percentage of piston sizes and the sample size of pistons, this finds the probablity of 2 situations. 1, if theres no more than 2 rejected pistons. 2, containing atleast 2 rejects. 
DATE: 7-17-2019 
*/
int main() {
  float dp, ps; //defective percentage, size of pistons
  float ans=0; 
  cin>>dp>>ps;

  //contain no more than 2 rejects 
  for(int i=0;i<=2;i++)
  {
    binomialDistribution answer(ps-i, ps, 1-dp/100);
    ans+=answer.calcBiDis();
  }

  cout<<fixed<<setprecision(3)<<ans<<endl; //3 decimal answer
  ans=0;
  //contain atleast 2 rejects
  for(int i=2;i<=ps;i++)
  {
    binomialDistribution answer(ps-i, ps, 1-dp/100);
    ans+=answer.calcBiDis();
  }

  cout<<fixed<<setprecision(3)<<ans<<endl; 

  return 0;
}