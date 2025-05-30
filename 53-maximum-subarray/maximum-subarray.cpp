class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        int cs = 0,maximumsum = INT_MIN;
        for(int i =0;i<nums.size();i++)
        {
            cs += nums[i];
            maximumsum = max(cs, maximumsum);

            if(cs < 0)
            {
                cs = 0;
            }
        }
        return maximumsum;*/

         int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSum = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};