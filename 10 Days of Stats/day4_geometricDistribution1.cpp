#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

float geometricDistribution(float n, float p);

/*
PURPOSE: Using geometric distribution, inputting the percentage of when a machine defects, the probablity of the 1st defect happening in the 5th inspection can be found.
DATE: 7-18-2019 
*/
int main() {
  float d1, d2; //defective probablity
  float inspec; //the inspection where 1st defect will occur
  cin>>d1>>d2>>inspec;

  cout<<fixed<<setprecision(3)<<geometricDistribution(inspec, d1/d2);
    
  return 0;
}

/*
PURPOSE: Finds Geometric Distribution. g(n,p)=q^(n-1)*p.
DATE: 7-18-2019 
*/
float geometricDistribution(float n, float p){

  return pow((1-p), (n-1)) * p;
}
