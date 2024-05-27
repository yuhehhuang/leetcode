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
    int rob(TreeNode* root) {
      vector<int>ans=robTree(root);
      return max(ans[0],ans[1]);  
    }
    vector<int> robTree(TreeNode* node){
        if(node==NULL){
            return {0,0};
        }
        //後序遍歷
        vector<int> left=robTree(node->left);
        vector<int>right=robTree(node->right);
        //中 處理
        //val1=偷 val2=不偷
        //[偷,不偷]
        int val1=node->val+left[1]+right[1]
        int val2=max(left[0],left[1])+max(right[0],right[1]);
        return {val1,val2};

    }
};