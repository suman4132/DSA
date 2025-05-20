class Solution {
public:
   void backtracking(vector<int>&candidate, int target, vector<vector<int>>&ans, vector<int>&temp,int start)
   {
    if(target == 0)
    {
        ans.push_back(temp);
        return ;
    }
    if(target < 0)
    {
        return ;
    }
    for(int i = start;i<candidate.size();i++)
    {
        temp.push_back(candidate[i]);
        backtracking(candidate, target-candidate[i], ans,temp,i);
        temp.pop_back();
    }
   }
    vector<vector<int>> combinationSum(vector<int>& candidate, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        backtracking(candidate,target, ans,temp,0);
        return ans;

    }
};