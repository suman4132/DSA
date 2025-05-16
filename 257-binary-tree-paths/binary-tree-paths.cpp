/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void backtracking(TreeNode* root, string temp, vector<string>& ans){
        // bc
        if(!root) 
            return;
        if(!root->left && !root->right)
        {
            temp+= to_string(root->val);
            ans.push_back(temp);
        }
        temp+= to_string(root->val) + "->";
        backtracking(root->left, temp, ans);
        backtracking(root->right, temp, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp="";
        backtracking(root, temp, ans);
        return ans;
    }
};