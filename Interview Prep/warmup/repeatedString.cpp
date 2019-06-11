#include <bits/stdc++.h>

using namespace std;

long repeatedString(string s, long n) {
  long aTotal=0; //total number of a's in the string.
  
  if (n > s.length()) { //the string repeats
    int aStr = count(s.begin(), s.end(), 'a'); // how many a's are in the string

    if(n%s.length() == 0){ //if even
      aTotal = aStr * (n/s.length()); //aStr * Quotient 
    }
    else{ //if odd 
      aTotal = ((n/s.length())*aStr)+count(s.begin(), s.begin() + n%s.length(), 'a'); //(Quotient*aStr)+(counting the remainder of a's in the string)
    }

  } 
  else if (s.length() > n) { //string doesnt repeat and is eventually cut off when counting
    aTotal = count(s.begin(), s.begin() + n, 'a');
  } 
  else { // s.length == n. string can be just be counted start to finish
    aTotal = count(s.begin(), s.end(), 'a');
  }

  return aTotal;
}

int main() //hackerrank code
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}