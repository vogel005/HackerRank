#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int jumpingOnClouds(vector<int> c) {
  int jump=0; //jump count
  int end = c.size(); //end of clouds 

  int i =0;
  while(i < end)
  {
    if(i+1 >= end) //if the end has been reached
      i++;
    else if(i+2 >= end){ //if end is within 2 ranges of a jump
      if(c[i+1] == 0){
        jump++;
        i++;
      }
      else
        i++;
    }
    else{ //if the end is not within 1 or 2 ranges of a jump
      if(c[i+1] ==0 && c[i+2] ==0){ // 000, 2 range jump
        jump++;
        i+=2;
      }
      else if(c[i+1]==0 && c[i+2]==1){ //001, 1 range jump
        jump++;
        i++;
      }
      else if(c[i+1]==1 && c[i+2]==0){ //010, 2 range jump
        jump++;
        i+=2;
      }
    }
  }

  return jump;
}

int main() //hackerrank code
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) { //hackerrank code
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