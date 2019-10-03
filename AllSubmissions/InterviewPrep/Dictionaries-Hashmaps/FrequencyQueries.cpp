/*
PURPOSE: Given a series of operations from a query, an unordered map is used to insert, delete, and find frequency of the given numbers. 
DATE: 9-16-2019
PARAMETERS:
vector<vector<int>> queries; [i][0] contains an operation number from 1-3. 1 is insert, 2 is delete, 3 is to check if frequency exists in map. [i][1] contains corrosponding number.
int q; Size of queries. 
RETURN: 
vector<int> ans; 1s and 0s based upon the results of the 3rd operation. 1 if frequency exists, 0 if not.
*/
string freqQuery(vector<vector<int>> queries, int q) {
  unordered_map<int,int> first, second;
  // first is <number, frequency>
  // second is <frequency, frequencyCount> 
  string ans; 

  for(int i=0;i<q;i++)
  { 
    int n=queries[i][1]; //the number being implemented by the query

    switch(queries[i][0]){
      case 1: { //1. insert
        int temp = first[n]; //current frequency of n.

        if(temp>0) //n was already present
          second[temp]--;
        
        //add n
        first[n]++; 
        second[first[n]]++; // updates frequency count
      }
        break;

      case 2: { //2. delete
        int temp = first[n];

        if(temp>0){
          //n is present
          second[temp]--; //update frequenct count
          first[n]--; //delete number
          second[first[n]]++; // update frequency count
        }
      }
        break;
        
      default: { //3. compare frequencies
        int temp = second[n];
        if(temp>0)
          ans.append("1\n");
        else
          ans.append("0\n");
      }
        break;
    }
  }

  return ans;
}