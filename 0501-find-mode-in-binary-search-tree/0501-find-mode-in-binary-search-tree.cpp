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
    vector<int>vec;
    int maxCount=0;
    int count=0;
    TreeNode* pre=NULL;
    void dfs(TreeNode*root){
        if(root==NULL){
            return ;
        }
        dfs(root->left);
        if(pre==NULL){
            count=1;
        }
        else if(pre->val==root->val){
            count++;
        }
        else{
            count=1;
        }
        pre=root;
        if(count==maxCount){
            vec.push_back(root->val);
        }
        if(count>maxCount){
            maxCount=count;
            vec.clear();
            vec.push_back(root->val);
        }
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = NULL; // 记录前一个节点
        dfs(root);
        return vec;
    }
};