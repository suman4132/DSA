class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int prev1=0;//dp[n-1]
        int prev2=0;//dp[n-2]
        for(int val: nums){
            int temp=prev1;
            prev1=max(prev2+val,prev1);
            prev2=temp;
        }
        return prev1;
        
    }
};