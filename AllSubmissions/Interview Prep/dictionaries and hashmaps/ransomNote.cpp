#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Checks to see if a magazine has enough case sensitive words to put on a
ransom note 
DATE: 5-21-2019 
PARAMETERS:
* magazine, essentially the dictionary of words the ransom note can be made out
of
* note, what the desired ransom note should be
VARIABLES:
* magMap, will contain a word and how many times it appears in the magazine
* it, iterator to check the value for each word
*/
void checkMagazine(vector<string> magazine, vector<string> note) {
  unordered_map<string, int> magMap; 
  //inserts an instance of a word and increments its value
  for(auto const& word: magazine)
    magMap[word]++;

  //searches through the ransom note, seeing if the words appear in the magazine. if find reaches the end of the map OR word has been used up already, function ends.
  for(auto const& word: note)
  {
    const auto it = magMap.find(word);
    if(it == magMap.end() || (it->second = --it->second) < 0){
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
  return;
}