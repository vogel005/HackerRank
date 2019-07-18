#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

float geometricDistribution(float n, float p);

/*
PURPOSE: Using geometric distribution, inputting the percentage of when a machine defects, the probablity of the 1st defect happening in 5 inspections can be found.
DATE: 7-18-2019 
*/
int main() {
  float d1, d2; //defective probablity
  float inspec; //the inspection where 1st defect will occur
  float ans=0; //sum of geometric distribution from 1-5 inspections
  cin>>d1>>d2>>inspec;

  for(int i=1;i<=inspec;i++)
    ans+=geometricDistribution(i, d1/d2);

  cout<<fixed<<setprecision(3)<<ans;
    
  return 0;
}

/*
PURPOSE: Finds Geometric Distribution. g(n,p)=q^(n-1)*p.
DATE: 7-18-2019 
*/
float geometricDistribution(float n, float p){

  return pow((1-p), (n-1)) * p;
}
