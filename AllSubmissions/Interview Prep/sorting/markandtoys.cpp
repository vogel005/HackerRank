#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
PURPOSE: Returns the maximum amount of toys that can be bought while shopping with a certain budget 
DATE: 5-22-2019
PARAMETERS:
* vector<int> prices, list of prices.
* int k, budget that can be spent
VARIABLES:
* int maxToys, how many toys can be bought
* int total, total price of how many toys can be bought
*/
int maximumToys(vector<int> prices, int k) {
  int maxToys =0; 
  int total=0;

  sort(prices.begin(), prices.end());

  for(int i=0; i < prices.size(); i++)
  {
    if(total + prices[i] <= k){
      total +=prices[i];
      maxToys++;
    }
    else 
      i=prices.size(); //ends for loop after the price total goes over budget 
  }

  return maxToys;
}

int main() //HACKERRANK CODE
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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
