

//Finds how many triplets can be created from a given ratio within an array.
long countTriplets(vector<long> arr, long r) {
  unordered_map<long,long> numbers, triplets; 
  long long count=0;

  for(vector<int>::size_type i = arr.size(); i-- !=0;)
  {
    long num =arr[i];
    long scaled =arr[i]*r;

    if(triplets.count(scaled)){
      count +=triplets[scaled];
    }

    if(numbers.count(scaled)){
      triplets[num] +=numbers[scaled];
    }
    numbers[num]++;
  }

  return count;
}