
/*
PURPOSE: Finds the maximum value between all numbers of N, such that A&B is less than K.
DATE: 7-11-2019
PARAMETERS:
int n; a set of numbers, 1 through n.
int k; the result of A&B must be less than k. 
VARIABLE:
int max; maximum value of A&B that is less than k.
int result; A&B of all numbers within N. 
*/
int maxval(int n, int k){
  int max=0;

  for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++){
      int result=i&j;
      if((result>max)&&(result<k))
        max=result;
    }

  return max;
}
