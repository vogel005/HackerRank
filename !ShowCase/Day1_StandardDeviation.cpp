#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

/*
PURPOSE: Finds the Standard Deviation through finding the variance and mean of a given series of numbers.
DATE CREATED: 6-21-2019
LAST MODIFIED: 7-19-2019
*/
class StandardDeviation {
  private:
	vector<int> arr;
	float u=0;
	float o2=0; 
	float o=0;

  public:
	StandardDeviation(vector<int> arr) {
		this->arr=arr;
	}

	//u, mean of arr
	float Mean(){
		for(int i=0;i<arr.size();i++)
			u+=arr[i];

		u/=arr.size();

		return u;
	}
	//o^2, variance, average magnitude of arr
	float Variance(){
		u=Mean();

		for(int i=0;i<arr.size();i++)
			o2+=pow(arr[i]-u,2);

		o2/=arr.size();

		return o2;
	}
	//o, standard deviation, square root of variation 
	float SD(){
		o2=Variance();

		o=sqrt(o2);

		return o;
	}
};


/*
PURPOSE: Fills vector with numbers, creates StandardDeviation class, displays the calculation for standard deviation with 1 decimal point.
DATE CREATED: 6-21-2019
LAST MODIFIED: 7-19-2019
*/
int main() {
  int n;
  cin>>n;
  vector<int> arr(n);

  for(int i=0;i<n;i++)
    cin>>arr[i];
  
  StandardDeviation answer(arr);

  cout<<fixed<<setprecision(1)<<answer.SD()<<endl;

  return 0;
}