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
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        return pathSumR(root,targetSum);
    }
    int pathSumR(TreeNode*root,int &targetSum){//pathSumR是以
        if(root==NULL){
            return 0;
        }
        return pathSumOneR(root,targetSum,0)+pathSumR(root->left,targetSum)+pathSumR(root->right,targetSum);
    }
    int pathSumOneR(TreeNode* root,int&targetSum,long curSum){
        if(root==NULL){
            return 0;
        }
        return (curSum + root->val == targetSum ? 1 : 0) +pathSumOneR(root->left, targetSum, curSum + root->val) +pathSumOneR(root->right, targetSum, curSum + root->val);
    }
};