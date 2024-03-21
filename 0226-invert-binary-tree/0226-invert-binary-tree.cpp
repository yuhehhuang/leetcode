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
    TreeNode* invertTree(TreeNode* root) {
     if(root==NULL){
        return NULL;
     }
     queue<TreeNode*> que;
     que.push(root);
     while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++){
            TreeNode* tmp=que.front();
            que.pop();
            swap(tmp->left,tmp->right);
            if(tmp->left){
                que.push(tmp->left);
            }
            if(tmp->right){
                que.push(tmp->right);
            }
        }
     }
     return root;
    }
};