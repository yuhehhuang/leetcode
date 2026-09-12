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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            if(root->left==NULL&&root->right==NULL){
                TreeNode *tmp=root;
                delete tmp;
                return NULL;
            }
            else if(root->left==NULL&&&root->right!=NULL){
                TreeNode* tmp=root->right;
                delete root;
                return tmp;
            }
            else if(root->left!=NULL&&root->right==NULL){
                TreeNode* tmp=root->left;
                delete root;
                return tmp;
            }
            else{
                TreeNode* cur=root->right;
                while(cur->left!=NULL){
                    cur=cur->left;
                }
                cur->left=root->left;
                TreeNode* tmp=root;
                root=root->right;
                delete tmp;
                return root;
            }
        }
        //以上都是"終止條件"
        //以下是"遞迴"
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};