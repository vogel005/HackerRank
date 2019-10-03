//Niece wants a Bday cake with the candle amount matching her age. She can only blow out the tallest candles. 
int birthdayCakeCandles(vector<int> ar) {
  bool less=true;
  int i=0;
  
  sort(ar.begin(), ar.end(), greater<int>());
  int tall=ar[0];
  while(less)
  {
    if(ar[i]==tall&&i<ar.size())
      i++;
    else 
      less=false;
  }

  return i;
}