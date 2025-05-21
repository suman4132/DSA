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
        if(i>start && candidate[i] == candidate[i-1])
        {
            continue;
        }
        // if(candidate[i] > target)
        // {
        //     break;
        // }
        temp.push_back(candidate[i]);
        backtracking(candidate, target-candidate[i], ans,temp,i+1);
        temp.pop_back();
    }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target, ans,temp,0);
        return ans; 
    }
};