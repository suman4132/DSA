class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int start) {
        ans.push_back(subset); // Push the current subset to the answer
        for (int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]); // Include the current element
            backtrack(ans, subset, nums, i + 1); // Recur for the next elements
            subset.pop_back(); // Backtrack by removing the current element
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sorting is optional but can help with ordered output
        vector<int> subset;
        backtrack(ans, subset, nums, 0);
        return ans;
    }
};