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
 void pre_Tra(TreeNode* root,vector<int>& arr){
    if(root==NULL){
        return ;
    }
    arr.push_back(root->val);
    pre_Tra(root->left,arr);
    pre_Tra(root->right,arr);
    return;
 }
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>ans;
        pre_Tra(root,ans);
        return ans;
    }
};