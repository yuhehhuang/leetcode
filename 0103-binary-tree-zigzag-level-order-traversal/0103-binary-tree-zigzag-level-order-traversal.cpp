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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>que;
        que.push(root);
        vector<vector<int>>ans;
        while(!que.empty()){
            vector<int>vals;
            for(int i=que.size();i>0;--i){
                TreeNode* node=que.front();
                que.pop();
                vals.push_back(node->val);
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            if(ans.size()%2){
                reverse(vals.begin(),vals.end());
            }
            ans.push_back(vals);
        }
        return ans;
    }
};