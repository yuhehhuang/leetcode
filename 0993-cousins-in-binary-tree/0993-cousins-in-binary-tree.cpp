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
    void dfs(TreeNode*root,TreeNode*parent,int depth,int find_element,int& find_depth,TreeNode*& find_parent){
        if(root==NULL){
            return;
        }
        if(root->val==find_element){
            find_depth=depth;
            find_parent=parent;
            return;
        }
        dfs(root->left,root,depth+1,find_element,find_depth,find_parent);
        dfs(root->right,root,depth+1,find_element,find_depth,find_parent);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root){
            return false;
        }
        TreeNode* parentX=NULL;
        TreeNode* parentY=NULL;
        int depthX;
        int depthY;
        dfs(root,NULL,0,x,depthX,parentX);
        dfs(root,NULL,0,y,depthY,parentY);
        return (depthX==depthY)&&(parentX!=parentY);
    }
};