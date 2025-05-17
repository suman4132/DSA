class Solution {
public:
   void backtracking(vector<vector<int>>&ans, vector<int>&arr,int start)
   { 
     if(start == arr.size())
     {
        ans.push_back(arr);
        return ;
     }
     for(int i =start;i<arr.size();i++)
     {
        swap(arr[start], arr[i]);
        backtracking(ans, arr, start + 1);
        swap(arr[start], arr[i]);
     }

   }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
       
       backtracking(ans,nums,0 );
       return ans;
       
    }
};