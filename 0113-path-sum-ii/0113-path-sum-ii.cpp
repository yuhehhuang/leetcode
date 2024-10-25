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
    void dfs(TreeNode*root,int targetSum,vector<int>path,int sum,vector<vector<int>>&ans){
        //
        if(root==NULL){
            return ;
        }
        //
        sum += root->val;
        path.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&sum==targetSum){
            ans.push_back(path);
        }
        dfs(root->left,targetSum,path,sum,ans);
        dfs(root->right,targetSum,path,sum,ans);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>path;
        vector<vector<int>>ans;
        dfs(root,targetSum,path,sum,ans);
        return ans;
    }
};