#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
PURPOSE: Adds up all unimportant + k amount of important contests to a returning luck value. Removes from sum if theres more important contests than k.
DATE: 5-28-2019
PARAMETERS: 
* int k, the amount of important contests that Lena can lose
* vector<vector<int>> contests, contains a Luck value at j=0, and an importance level of 1 or 0 at j=1. 
VARIABLES:
* int count, is the luck value sum of contests.
* vector<int> important, contains all the important contest values, so that they can be sorted and added/subtracted correctly.
*/
int luckBalance(int k, vector<vector<int>> contests) {
  int count=0;
  vector<int> important; 

  for(int i = 0; i < contests.size(); i++) {
    if (contests[i][1] == 1)
      important.push_back(contests[i][0]);
    else
      count += contests[i][0];
  }

  sort(important.begin(), important.end(), greater<int>()); //add the higher contest values first

  for(int i=0; i < important.size(); i++)
  {
    if(i>=k) //if theres more important tasks than k
      count-=important[i];
    else
      count+=important[i];
  }
  return count;
}

int main() //HACKERRANK CODE
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

    fout.close();

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