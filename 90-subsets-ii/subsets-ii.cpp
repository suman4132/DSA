class Solution {
public:
void backtracking(vector<vector<int>>&ans, vector<int>&temp,vector<int>&nums, int start)
{
    ans.push_back(temp);
    for(int i = start;i<nums.size();i++)
    {
         if(i > start && nums[i] == nums[i -1] )
          continue;
          temp.push_back(nums[i]);
          backtracking(ans, temp, nums, i+1);
          temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        backtracking(ans, temp, nums, 0);
        return ans;
    }
};