class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int count =0;
        int result =0;
        for(auto & c :s)
        {
          if(c == 'R')
          {
            count++;
          }
          if(c == 'L')
          {
            count--;
          }
          if(count == 0)
          {
            result++;
          }
        }
        return result;
    }
};