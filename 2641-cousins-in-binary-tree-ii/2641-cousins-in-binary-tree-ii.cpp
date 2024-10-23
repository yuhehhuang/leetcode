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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        queue<TreeNode*>que;
        que.push(root);
        vector<int>levelsums;
        while(!que.empty()){
            int levelsum=0;
            int n=que.size();
            for(int i=0;i<n;i++){
                TreeNode* cur=que.front();
                que.pop();
                levelsum+=cur->val;
                if(cur->left!=NULL){
                    que.push(cur->left);
                }
                if(cur->right!=NULL){
                    que.push(cur->right);
                }            
            }
            levelsums.push_back(levelsum);
        }
        que.push(root);
        root->val=0;
        int levelIndex=1;
        while(!que.empty()){
            int n=que.size();
            for(int i=0;i<n;i++){
                TreeNode* cur=que.front();
                que.pop();
                int siblingSum=(cur->left?cur->left->val:0)+(cur->right?cur->right->val:0);
                if(cur->left){
                    cur->left->val=levelsums[levelIndex]-siblingSum;
                    que.push(cur->left);
                }
                if(cur->right){
                    cur->right->val=levelsums[levelIndex]-siblingSum;
                    que.push(cur->right);
                }
            }
            levelIndex++;
        }
        return root;

    }
};