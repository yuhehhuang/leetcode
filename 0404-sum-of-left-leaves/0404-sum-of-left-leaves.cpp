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
    void DFS(TreeNode* cur,bool left,int &total){
        if(cur==NULL){ //用於right leaf node return OR 空樹
            return ;
        }
        if(left&&cur->left==NULL&&cur->right==NULL){//when we meet left leaf node
            total+=cur->val;
            return;
        }
        DFS(cur->left,true,total);
        DFS(cur->right,false,total);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int total=0;
        DFS(root,false,total);
        return total;
    }
};