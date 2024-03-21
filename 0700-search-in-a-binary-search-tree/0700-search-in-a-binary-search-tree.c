/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode* find=root;
    while(find!=NULL){
        if(find->val==val){
            return find;
        }
        else if(find->val<val){
            find=find->right;
        }
        else{
            find=find->left;
        }
    }
    return NULL;
}