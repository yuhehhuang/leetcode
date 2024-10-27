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
    void every_is_father(TreeNode*root,int& ans){
        if(root==NULL){
            return ;
        }
        int lenth=-1;
        dfs(root,lenth,0,ans);
        dfs(root,lenth,1,ans);
        every_is_father(root->left,ans);
        every_is_father(root->right,ans);
    }
    void dfs(TreeNode*root,int lenth,bool dir,int& ans){
        if(root==NULL){
            ans=max(ans,lenth);
            return ;
        }
        lenth++;
        if(dir==0){
            dfs(root->right,lenth,1,ans);
        }
        if(dir==1){
            dfs(root->left,lenth,0,ans);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        every_is_father(root,ans);
        return ans;
    }
};