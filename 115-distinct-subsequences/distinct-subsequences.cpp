class Solution {
public:
    int numDistinct(string s, string t) {
      int n = s.length(), m = t.length();

        // Optimization: If any character in t not in s, return 0 early
        unordered_set<char> charsInS(s.begin(), s.end());
        for (char c : t) {
            if (charsInS.find(c) == charsInS.end()) return 0;
        }

        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // Base case: empty t
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][m];
    }
};