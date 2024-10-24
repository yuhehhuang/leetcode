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
    void dfs(TreeNode*root,int big,int& cnt){
        if(root==NULL){
            return;
        }
        if(root->val>=big){
            cnt++;
            big=root->val;
        }
        dfs(root->left,big,cnt);
        dfs(root->right,big,cnt);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int big=root->val;
        int cnt=0;
        dfs(root,big,cnt);
        return cnt;
    }
};