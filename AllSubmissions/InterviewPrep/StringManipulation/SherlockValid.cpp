/*
PURPOSE: Checks if a given string follows the proper criteria: All characters within it have equal frequency. If one character's frequency is NOT equal to the others, then ALL INSTANCES of that character can be removed. HOWEVER, that is only allowed one time. 
DATE: 10-3-2019
PARAMETERS:
s; String containing random letters.
VARIABLES:
freq; Follows the frequency of each character within s.
first, second; Comparing the frequencies of all the characters to the first character within an ordered map. 
invalid; Counts how many times a character isn't equal to the other frequencies.
RETURN:
yn; Either says YES or NO depending on if string s was valid or not. 
*/
string isValid(string &s) {
  string yn="YES";
  map<char, int> freq;

  //linear search through s, tallying the frequency of each character. 
  for(int i=0; i<s.size();i++)
    freq[s[i]]++;

  int invalid=0;
  auto it=freq.begin();
  int first=it->second;
  //binary compare through freq to see if equal. counting amount of invalid times. 
  for(auto it=freq.begin(); it!=freq.end() && yn=="YES"; it++)
  {
    int second=it->second;
    
    if(first != second){
      invalid++;

      if(invalid>1) //s is invalid after 2
        yn="NO";
    }
  }

  return yn; 
}