
//Finds minimum number of swaps required for an Array of unique and consecutive numbers starting from 1.
int minimumSwaps(vector<int> arr) {
  int count=0;

  int i=0;
  while(i<arr.size()){
    if(arr[i]!=i+1){ //if number isn't in correct position, swap.
      swap(arr[i], arr[arr[i]-1]);
      count++;
    }

    if(arr[i]==i+1) //only increment if swapped in number is in correct position.
      i++;
  }

  return count;
}