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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        auto dfs=[&](auto&& dfs,TreeNode* node)->int{
            if(node==NULL){
                return -1;
            }
            int l_len=dfs(dfs,node->left)+1;
            int r_len=dfs(dfs,node->right)+1;
            ans=max(ans,l_len+r_len);
            return max(l_len,r_len);//當前子樹的最大鏈長
        };
        dfs(dfs,root);
        return ans;
    }
};