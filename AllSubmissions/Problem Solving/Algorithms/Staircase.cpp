//Prints out a staircase
void staircase(int n) {
  for(int i=1;i<=n;i++)
    cout<<string(n-i, ' ')<<string(i, '#')<<endl;
}