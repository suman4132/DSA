class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
         int n = bills.size();
         int fcount =0;
         int tcount=0;
         for(int i =0;i<n;i++)
         {
            if(bills[i] == 5)
            {
                fcount++;
            }
            if(bills[i] == 10)
            {
                if(fcount == 0)
                  return false;

                tcount++;
                fcount--;
            }
            if(bills[i] == 20)
            {
                if(fcount > 0 && tcount > 0)
                {
                tcount--;
                fcount--;
                }
                else if(fcount >= 3)
                {
                 fcount -= 3;
                }
                else
                {
                    return false;
                }
            }

         } 
            return true;
        
    }
};