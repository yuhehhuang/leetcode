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
    int ans=0;
    //右中左
   void  traversal(TreeNode* root){
        if(root==NULL){
            return ;
        }
        
        traversal(root->right);
        root->val+=ans;
        ans=root->val;
        traversal(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        ans=0;
        if(root==NULL){
            return NULL;
        }
        traversal(root);
        return root;
    }
};