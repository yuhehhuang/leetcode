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
void pre_Tra(struct TreeNode* root,int* arr, int* returnSize){
    if(root==NULL){
        return ;
    }
    arr[(*returnSize)++]=root->val;
    pre_Tra(root->left,arr,returnSize);
    pre_Tra(root->right,arr,returnSize);
    return ;
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize=0;
    if( root==NULL){
        return NULL;
    }
    int* ans=malloc(sizeof(int)*100);
    int* save_head=ans;
    pre_Tra(root,ans,returnSize);
    return save_head;
}