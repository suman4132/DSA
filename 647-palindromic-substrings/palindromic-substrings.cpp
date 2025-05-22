class Solution {
public:
  int palindromecheck(string s , int i,int j)
  {
    int ans =0;
    while(i >= 0 && j < s.length() && s[i] == s[j])
    {
        ans++;
        i--;
        j++;
    }
    return ans;
  }
    int countSubstrings(string s) {
        int n = s.length();
        int ans=0;
        for(int i =0;i<n;i++)
        {
           ans+=palindromecheck(s ,i,i);
           ans+=palindromecheck(s ,i,i+1);
        }
         return ans;
    }
};