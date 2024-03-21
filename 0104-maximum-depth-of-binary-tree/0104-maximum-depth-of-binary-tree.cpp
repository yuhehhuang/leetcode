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
    int maxDepth(TreeNode* root) {
        int depth=0;
        queue<TreeNode*>que;
        if(root!=NULL){
            que.push(root);
        }
        while(!que.empty()){
            int size=que.size();
            TreeNode*tmp;
            for(int i=0;i<size;i++){
                if(i==0){
                    tmp=que.front();
                    que.pop();
                    depth+=1;
                    
                }
                else{
                    tmp=que.front();
                    que.pop();
                }
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
            }
        }
        return depth;
    }
};