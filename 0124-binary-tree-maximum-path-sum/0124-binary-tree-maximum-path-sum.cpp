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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        auto dfs=[&](auto&&dfs,TreeNode* node){
            if(node==NULL){
                return 0;
            }
            int l_val=dfs(dfs,node->left);
            int r_val=dfs(dfs,node->right);
            ans=max(ans,l_val+r_val+node->val);
            return max(max(l_val,r_val)+node->val,0);
        };
        dfs(dfs,root);
        return ans;
    }
};