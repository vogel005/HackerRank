#include <bits/stdc++.h>

using namespace std;

/*
PURPOSE: Determines how many characters need to be deleted such that string s has no repeating letters adjacement e.q. ABABA...repeating.
DATE: 5-23-2019
PARAMETERS:
* string s, string containing A and/or B characters only.
VARIABLES:
* auto count, number of times a character was deleted in string s.
*/
int alternatingCharacters(string s) {
  auto count=0;

  for(auto i=0; i < s.size()-1; i++) //n-1 as we are comparing in pairs
  {
    if(s[i] == s[i+1]){ //if current and adjacent character are same, delete adjacement 
      s.erase(s.begin()+i+1);
      i--;
      count++;
    }
  }

  return count;
}

int main() //HACKERRANK CODE
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}