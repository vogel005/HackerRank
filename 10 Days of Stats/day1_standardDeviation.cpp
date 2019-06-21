#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

/*
PURPOSE: Finds the Standard Deviation through finding the variance and mean of a given series of numbers.
DATE: 6-21-2019
*/
class standardDeviation {
  private:
  vector<int> arr;
  float mean=0;
  float variance=0; 
  float sd=0;

  public:
  standardDeviation(vector<int> arr) {
    this->arr=arr;
  }

  //u, mean of arr
  float calcMean(){
    for(int i=0;i<arr.size();i++)
      mean+=arr[i];

    mean/=arr.size();

    return mean;
  }
  //o^2, average magnitude of arr
  float calcVariance(){
    mean=calcMean();

    for(int i=0;i<arr.size();i++)
      variance+=pow(arr[i]-mean,2);

    variance/=arr.size();

    return variance;
  }
  //o, square root of variation 
  float calcSD(){
    variance=calcVariance();

    sd=sqrt(variance);

    return sd;
  }
};


/*
PURPOSE: Fills vector with numbers, creates standardDeviation class, displays the calculation for standard deviation with 1 decimal point.
DATE: 6-21-2019
*/
int main() {
  int n;
  cin>>n;
  vector<int> arr(n);

  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  standardDeviation sd(arr);

  cout<<fixed<<setprecision(1)<<sd.calcSD()<<endl;

  return 0;
}