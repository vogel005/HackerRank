#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Determines how many characters need to be deleted between a & b for
letter frequency to be equal, so that they can be anagrams 
DATE: 5-23-2019
PARAMETERS:
* string a, string of letters
* string b, string of letters
VARIABLES:
* int count, the number of character differences between a & b
* vector<int> freq, frequency of each letter in alphabet between a & b
*/
int makeAnagram(string a, string b) {
  int count=0; 
  vector<int> freq(26,0); 

  for(auto i: a) 
    freq[i - 'a']++; //counts letter frequency in string a

  for(auto i: b)
    freq[i - 'a']--; //counts by decrementation, meaning if frequency is equal it will be 0

  for(auto i : freq)
    count += abs(i); //adds up any imbalances within freq 
  
  return count;
}

int main() //HACKERRANK CODE
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}