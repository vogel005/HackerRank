// returns a characters index
int NumChar(char c){
  return (c - 'a');
}

//Finds the count of all substring anagramic pairs 
int sherlockAndAnagrams(string s) {

  map<vector<int>,int> anagrams; //contains substrings and their frequencies

  for(int i=0; i<s.length();i++)
  {
    vector<int> freq(26, 0); //alphabet

    for(int j=i; j<s.length(); j++)
    {
      freq[NumChar(s[j])]++; //frequency of current substring

      anagrams[freq]++; //counts the frequency with anagrams
    }
  }

  int count=0;
  //permutations of all the substrings
  for(auto it=anagrams.begin(); it!=anagrams.end(); it++) 
  {
    int freq = it->second;
    count += ((freq)*(freq-1))/2;
  }

  return count;
}