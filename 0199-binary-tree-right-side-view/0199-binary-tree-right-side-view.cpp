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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;++i){
                TreeNode* cur=que.front();
                if(i==0){
                    ans.push_back(cur->val);
                }
                que.pop();
                if(cur->right){
                    que.push(cur->right);
                }
                if(cur->left){
                    que.push(cur->left);
                }
            }
        }
        return ans;
    }
};