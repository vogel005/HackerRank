//Min and Max sum based upon if 1 number was missing. Which is just, using math, the min is the sum minus largest number, and max is sum minus smallest number
void miniMaxSum(vector<int> arr) {
  long sum=0;

  for(int i=0;i<arr.size();i++)
    sum+=arr[i];

  sort(arr.begin(), arr.end());

  cout<<sum-arr[arr.size()-1]<<' '<<sum-arr[0]<<endl;
}