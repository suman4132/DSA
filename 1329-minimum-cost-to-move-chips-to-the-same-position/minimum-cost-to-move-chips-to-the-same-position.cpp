class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();

        int count =0;
        int evcount =0;
        for(int i =0;i<n;i++)
        {
          if(position[i]%2 == 0)
          {
            evcount++;
          }
          else
          {
            count++;
          }
        }
        return min(evcount, count); 
    }
};