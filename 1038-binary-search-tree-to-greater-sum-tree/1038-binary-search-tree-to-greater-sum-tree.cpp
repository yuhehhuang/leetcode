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
    int sum=0;
    void traversal(TreeNode* root){
        if(root==NULL){
            return ;
        }
        traversal(root->right);
        sum+=root->val;
        root->val=sum;
        traversal(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        //BST 右中左搜 可以排出由大到小
        traversal(root);
        return root;
    }
};