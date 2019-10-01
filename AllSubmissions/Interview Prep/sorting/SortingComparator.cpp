
//HackerRank Code
/*struct Player {
    int score;
    string name;
};*/


class Checker{
public:
    static int comparator(Player a, Player b)  {
	//scores are in descending order
      if(a.score < b.score)
        return -1;
      else if (a.score > b.score)
        return 1;
      else { //score equal  
		//name is ascending order
        for(int i=0; i<a.name.length() || i<b.name.length(); i++)
        {
          if(a.name[i] > b.name[i])
            return -1;
          else if(a.name[i] < b.name[i])
            return 1;
        }
      }
      return 0;
    }
};