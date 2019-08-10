#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


/*
PURPOSE: Finds the minimum absolute difference between all pairs
DATE: 5-24-2019
PARAMETERS:
* vector<int> arr, filled with positive and negative integers
VARIABLES:
* int min, minimum absolute difference 
* int diff, temporary value holding |i-j|
*/
int minimumAbsoluteDifference(vector<int> arr) {
  int min;

  sort(arr.begin(), arr.end()); //sorted, so it can be compared in consecutive pairs  

  for(int i=0; i < arr.size()-1; i++) 
  {
    int diff = abs(arr[i]-arr[i+1]);

    if(i == 0) //baseline min is the first value
      min = diff;
    else if(diff < min)
      min = diff;
  }

  return min;
}

int main() //HACKERRANK CODE
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

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
