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
    bool hasPathSum(TreeNode* root, int sum) {
       if(root==NULL){
        return false;
       }
       stack<pair<TreeNode*,int>>st;
       st.push(pair<TreeNode*,int>(root,root->val));
       while(!st.empty()){
         pair<TreeNode*, int> tmp = st.top();
        st.pop();
        if(tmp.first->left==NULL&&tmp.first->right==NULL&&sum==tmp.second){
            return true;
        }
        //stack先進後出 先放右再放左
        if(tmp.first->right){
        st.push(pair<TreeNode*,int>(tmp.first->right,tmp.second+tmp.first->right->val));
        }
        if(tmp.first->left){
        st.push(pair<TreeNode*,int>(tmp.first->left,tmp.second+tmp.first->left->val));
        }
       }
       return false;
    }
};