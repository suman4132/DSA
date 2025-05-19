class Solution {
public:
  void backtracking(vector<vector<int>>&ans,vector<int>&s,int n,int k,int st )
  {
    if(s.size() == k)
    {
        ans.push_back(s);
        return ;
    }
    for(int i =st;i<=n;i++ )
    {
        s.push_back(i);
        backtracking(ans,s,n,k,i+1);
        s.pop_back();

        
    }
  }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>s;
        backtracking(ans,s,n,k,1);

        return ans;
    }
};