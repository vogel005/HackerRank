#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

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

int main() //HACKERRANK CODE
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

    return 0;
}

vector<string> split_string(string input_string) { //HACKERRANK CODE
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}