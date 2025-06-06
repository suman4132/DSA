class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
          int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 1: Build the LCS DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Build the Shortest Common Supersequence using LCS
        string result;
        int i = n, j = m;

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result.push_back(str1[i - 1]);
                --i; --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                result.push_back(str1[i - 1]);
                --i;
            } else {
                result.push_back(str2[j - 1]);
                --j;
            }
        }

        // Append remaining characters
        while (i > 0) result.push_back(str1[--i]);
        while (j > 0) result.push_back(str2[--j]);

        reverse(result.begin(), result.end());
        return result;
    }
};