class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job(n, vector<int>(3)); 
        for (int i = 0; i < n; i++) {
            job[i][0] = startTime[i];
            job[i][1] = endTime[i];
            job[i][2] = profit[i];
        }

        sort(job.begin(), job.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        // DP array to store max profit until each job
        vector<int> dp(n, 0);
        dp[0] = job[0][2]; // profit of first job

        for (int i = 1; i < n; i++) {
            int inclProfit = job[i][2];

            // Binary search for the last job that doesn't conflict
            int l = binarySearch(job, i);
            if (l != -1) {
                inclProfit += dp[l];
            }

            // Take max of including or excluding the current job
            dp[i] = max(dp[i - 1], inclProfit);
        }

        return dp[n - 1];
    }

private:
    // Binary search to find the last non-conflicting job
    int binarySearch(vector<vector<int>>& job, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (job[mid][1] <= job[index][0]) {
                if (job[mid + 1][1] <= job[index][0])
                    low = mid + 1;
                else
                    return mid;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};