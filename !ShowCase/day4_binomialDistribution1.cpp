#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

/*
PURPOSE: Finds Binomial Distribution.
DATE CREATED: 7-16-2019
LAST MODIFIED: 7-19-2019
*/
class Binomial{
  private:
    float x; //number of success
    float n; //number of trial runs
    float p; //success of 1 trial
    float q; //failure of 1 trial

  public:
    Binomial(float x, float n, float p){
      this->x=x;
      this->n=n;
      this->p=p;
      q=1-p;
    }

    int Factorial(int num); //finds factorial of given number
    float nCx(); //nCx = n!/(x!*(n-x)!)
    float b(); //b(x,n,p) = (n x) * p^x * q^(n-x)
};

int Binomial::Factorial(int num) {
  return (num<2) ? 1 : num*Factorial(num-1);
}

float Binomial::nCx(){
  return Factorial(n) / (Factorial(x) * Factorial(n-x));
}

float Binomial::b(){
  return nCx() * pow(p,x) * pow(q,(n-x));
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
    Binomial answer(i,6,(br/(br+gr)));
    ans+=answer.b();
  }
  //3 decimal answer
  cout<<fixed<<setprecision(3)<<ans<<endl;

  return 0;
}