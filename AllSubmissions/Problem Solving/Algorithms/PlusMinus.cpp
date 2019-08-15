void plusMinus(vector<int> arr) {
  vector<int> ratio(3,0); //ratio of positive, negative, zero numbers

  for(int i=0;i<arr.size();i++)
    if(arr[i]>0)
      ratio[0]++;
    else if(arr[i]<0)
      ratio[1]++;
    else 
      ratio[2]++;

  cout<<fixed<<setprecision(6)<<(float)ratio[0]/arr.size()<<endl;
  cout<<fixed<<setprecision(6)<<(float)ratio[1]/arr.size()<<endl;
  cout<<fixed<<setprecision(6)<<(float)ratio[2]/arr.size()<<endl;

}