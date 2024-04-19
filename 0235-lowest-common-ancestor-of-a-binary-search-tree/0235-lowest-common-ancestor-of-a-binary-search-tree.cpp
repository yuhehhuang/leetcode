/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
////最近共同祖先之值一定介於[p,q]所以找到這條件就是答案
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val>p->val&&root->val>q->val){
            TreeNode* left=lowestCommonAncestor(root->left,p,q);
            if(left!=NULL){
                return left;
            }
        }
        if(root->val<p->val&&root->val<q->val){
            TreeNode* right=lowestCommonAncestor(root->right,p,q);
            if(right!=NULL){
                return right;
            }
        }
        return root;
        

    }
};