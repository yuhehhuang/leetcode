/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode* root,int *returnSize,int* ans){
    if(root==NULL){
        return;
    }
    // if(root->left==NULL&&root->right==NULL){
    //     ans[(*returnSize)++]=root->val;
    //     return;
    // }
    dfs(root->left,returnSize,ans);
    ans[(*returnSize)++]=root->val;
    dfs(root->right,returnSize,ans);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int*ans = (int*)malloc(sizeof(int)*100);
    *returnSize=0;
    dfs(root,returnSize,ans);
    return ans;
}