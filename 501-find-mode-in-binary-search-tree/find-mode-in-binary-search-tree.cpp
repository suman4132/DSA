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
    void inorder(TreeNode* root, vector<int>&v)
    {
        if(!root)
         return ;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v); 
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        inorder(root, v);
        unordered_map<int, int>temp;
        for(int i =0;i<v.size(); i++)
        {
           temp[v[i]]++;
        }
       int ma = 0;
        for(auto & [key, val] : temp)
        {
            ma = max(ma , val);
        }

        vector<int>mode;
        for(auto [key , val] : temp)
        {
            if(val == ma)
            {
                mode.push_back(key);
            }
        }

        return mode;
    }
};