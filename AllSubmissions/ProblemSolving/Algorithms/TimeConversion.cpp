//Converts 12AM/PM clock format into military 24hour time.
string timeConversion(string s) {
  char ap= s[8];
  int hh= stoi(s.substr(0,2));
  s.pop_back();
  s.pop_back();

  if(hh==12){
    if(ap=='A')
      s.replace(0,2,"00");
  }
  else if(ap=='P'){
    hh+=12;
    s.replace(0,2, to_string(hh));
  }

  return s;
}