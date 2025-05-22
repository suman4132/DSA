class Solution {
public:
//   int palindromcheck(string s , int i,int j)
//   {
//     int ans =0;
//     while(i >= 0 && j < s.length() && s[i] == s[j])
//     {
//         ans++;
//         i--;
//         j++;
//     }
//     return ans;
//   }


/*dp approach*/
int countOfPalindrom(string s)
{
    int n = s.length();
        int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 1 || len == 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j])
                    count++;
            }
        }

        return count;
    }





    int countSubstrings(string s) {
        // int n = s.length();
        // int ans=0;
        // for(int i =0;i<n;i++)
        // {
        //    ans+=palindromcheck(s ,i,i);
        //    ans+=palindromcheck(s ,i,i+1);
        // }
        //  return ans;

        return countOfPalindrom(s);
    }
};