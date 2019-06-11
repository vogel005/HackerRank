#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
PURPOSE: Bubble sorts vector in ascending order and counts how many swaps happened
DATE: 5-22-2019
PARAMETERS: 
* vector<int> a, an unsorted vector.
VARIABLES:
* int count, increments each time a swap happens
*/
void countSwaps(vector<int> a) {
  int count =0; 
 
  for (int i = 0; i < a.size(); i++) 
  {
    for (int j = 0; j < a.size()-i-1; j++) 
    {
      // Swap adjacent elements if they are in decreasing order
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
        count++;
      }
    }
  }

  cout << "Array is sorted in " << count << " swaps." << endl;
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a[a.size()-1] << endl;
  return;
}

int main() //HACKERRANK CODE
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    countSwaps(a);

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
