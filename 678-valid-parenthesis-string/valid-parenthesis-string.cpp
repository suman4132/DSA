class Solution {
public:
    bool checkValidString(string s) {
         int l=0,r=0;
        int n =s.size();
        for(int i =0;i<n;i++){
            if(s[i]=='(')
               l++;
            else if(s[i] == ')')
               l-- ;
            else 
               l++;
           if(l < 0 )
             return false; 
            if(s[n-i-1] == ')')
                r++;
            else if(s[n-1-i] == '(')
                r--;
            else
               r++;
            if(r<0)
               return false;       
                          
        }
        return true;
    }
};