/*
PURPOSE: Finds median of an already sorted vector.
DATE: 9-26-2019
PARAMETERS:
temp; A sorted vector.
VARIABLES:
n; Size of temp, for readability.
*/
float getSortedMedian(vector<int> &temp){
  int n=temp.size(); 

  if(n%2==0)//even
    return (float)(temp[n/2] + temp[(n-1)/2])/2.0;

  return (float)temp[n/2]; //odd
}

/*
PURPOSE: Finds if after a certain amount of trailing days (d), if someone's expenditures exceed 2x the median.
DATE: 9-26-2019
PARAMETERS:
expenditure; List of numbers of daily expenses.
d; Amount of trailing days that are required for analyzing.
VARIABLES:
trail; A vector that contains the current trailing days range within expenditure, sorted.
temp; expenditure[i], given temporary value for better readability.
median; Current median based upon med_arr.
low; Iterator that finds the lower bound of current number, so that it can be inserted sorted.
it; Finds the the first number within the range to be deleted.
RETURN:
notif; Amount of notification warnings that appeared.
*/
int activityNotifications(vector<int> expenditure, int d) {
  int notif=0;

  vector<int> trail;
  trail.assign(expenditure.begin(), expenditure.begin()+d);
  sort(trail.begin(), trail.end());

  for(int i=d;i<expenditure.size();i++)
  {
    int temp = expenditure[i];

    float median = getSortedMedian(trail);

    if((float)temp>=(float)2.0*median)
      notif++;

    //add newest number, sorted.
    auto low = lower_bound(trail.begin(), trail.end(), temp);
    trail.insert(low, temp);
    //delete the top number. 
    auto it = find(trail.begin(), trail.end(), expenditure[i-d]);
    trail.erase(it);
  }

  return notif;
}
