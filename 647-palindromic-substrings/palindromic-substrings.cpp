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

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                int k = j + i - 1;

                if (s[j] == s[k]) {
                    if (i == 1 || i == 2)
                        dp[j][k] = true;
                    else
                        dp[j][k] = dp[j + 1][k - 1];
                }

                if (dp[j][k])
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