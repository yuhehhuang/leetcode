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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ans;
        vector<TreeNode*>cur={root};
        while(cur.size()){
            vector<TreeNode*>next;
            vector<int>vals;
            for(auto node:cur){
                vals.push_back(node->val);
                if(node->left){
                    next.push_back(node->left);
                }
                if(node->right){
                    next.push_back(node->right);
                }
            }
            cur=move(next);
            ans.push_back(vals);
        }
        return ans;
        
    }
};