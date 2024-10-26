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
    int pathSumR(TreeNode*root,int &targetSum){//以root為根算答案+孩子為根算答案
        if(root==NULL){
            return 0;
        }
        return pathSumOneR(root,targetSum,0)+pathSumR(root->left,targetSum)+pathSumR(root->right,targetSum);
    }
    int pathSumOneR(TreeNode* root,int&targetSum,long curSum){
        if(root==NULL){
            return 0;
        }
        curSum+=root->val;
        int paths = (curSum == targetSum) ? 1 : 0;
        paths+=pathSumOneR(root->left, targetSum, curSum);
        paths+=pathSumOneR(root->right, targetSum, curSum);
        return paths;
    }
};