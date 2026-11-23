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
    if(root->left==NULL&&root->right==NULL){
        accumulate+=root->val;
        return targetSum==accumulate;
    }
    else{
        accumulate +=root->val;
    return dfs(root->left,targetSum,accumulate)||dfs(root->right,targetSum,accumulate);
    }
    return false;
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL){
        return false;
    }

    return dfs(root,targetSum,0);
}