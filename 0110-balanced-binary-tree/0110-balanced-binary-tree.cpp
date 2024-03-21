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
    int gethi(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int lefthi=gethi(node->left);
        if(lefthi==-1){
            return -1;
        }
        int righthi=gethi(node->right);
        if(righthi==-1){
            return -1;
        }
        return abs(lefthi-righthi)>1?-1:1+max(lefthi,righthi);
    }
    bool isBalanced(TreeNode* root) {
        return gethi(root)==-1?false:true;
    }
};