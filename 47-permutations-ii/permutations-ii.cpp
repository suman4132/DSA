class Solution {
public:
    void backtracking(vector<vector<int>>& result, vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        unordered_set<int> used; 
        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) 
                continue; 
            used.insert(nums[i]);
            swap(nums[start], nums[i]);
            backtracking(result, nums, start + 1);
            swap(nums[start], nums[i]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        backtracking(result, nums, 0);
        return result;
    }
};
