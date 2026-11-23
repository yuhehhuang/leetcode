/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root,int targetSum,int accumulate){
    if(root==NULL){
        return false;
    }
    accumulate+=root->val;
    if(root->left==NULL&&root->right==NULL){
        return targetSum==accumulate;
    }
    return dfs(root->left,targetSum,accumulate)||dfs(root->right,targetSum,accumulate);
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL){
        return false;
    }

    return dfs(root,targetSum,0);
}