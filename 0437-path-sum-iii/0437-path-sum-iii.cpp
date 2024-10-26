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
        int paths=0;
        pathSumR(root,targetSum,paths);
        return paths;
    }
    void pathSumR(TreeNode*root,int &targetSum,int& paths){//呼叫每個node當作始祖來算pathSumOneR
        if(root==NULL){
            return ;
        }
        pathSumOneR(root,targetSum,0,paths);
        pathSumR(root->left,targetSum,paths);
        pathSumR(root->right,targetSum,paths);
    }
    void pathSumOneR(TreeNode* root,int&targetSum,long curSum,int& paths){//以root為根算所有可能path
        if(root==NULL){
            return ;
        }
        curSum+=root->val;
        if(curSum==targetSum){
            paths++;
        }
        pathSumOneR(root->left,targetSum,curSum,paths);
        pathSumOneR(root->right,targetSum,curSum,paths);
    }
};
