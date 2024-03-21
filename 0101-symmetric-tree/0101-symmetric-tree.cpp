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
    bool compare(TreeNode* left,TreeNode* right){
        if(!left&&right){
            return false;
        }
        else if(left&&!right){
            return false;
        }
        else if(!left&&!right){ //先排除空節點 這樣下面left->val !=right->val才不會出錯
            return true;
        }
        else if(left->val!=right->val){
            return false;
        }
        else{
        //底下是left->val==right->val的情況下比其他
        bool outside=compare(left->left,right->right);
        bool inside=compare(left->right,right->left);
        bool ans=outside&&inside;
        return ans;
        }

    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return compare(root->left,root->right);
    }
};