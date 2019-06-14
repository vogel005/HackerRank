#include <map>
#include <iostream>
#include <iterator>
using namespace std;


/*
PURPOSE:
DATE: 6-14-2019
INPUT:
* int n; the amount of people in the phone book.
* map<string, int> phonebook; a series of paired names and phone numbers.
VARIABLES:
*auto itr; and iterator to find the phone number value of a given name.
*/
int main() {
  map<string, int> phonebook;
  int n;
  string name;
  int num;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>name>>num;
    phonebook.insert({name, num});
  }
  
  while(cin>>name)
  {
    auto itr =phonebook.find(name);
    if(itr==phonebook.end())
      cout<<"Not found"<<endl;
    else
      cout<<name<<"="<<itr->second<<endl;
  }

  return 0;
}