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
    void travel(TreeNode* Node,vector<int>&path,vector<string>&result){
        path.push_back(Node->val);
        if(Node->left==NULL&&Node->right==NULL){//遇到leaf node 開始複製路徑
            string spath;
           for(int i=0;i<path.size()-1;i++){
            spath+=to_string(path[i]);
            spath+="->";
           }
           spath+=to_string(path[path.size()-1]);
           result.push_back(spath);                                       
            return ;
        }
        if(Node->left!=NULL){
            travel(Node->left,path,result);
            path.pop_back();
        }
        if(Node->right!=NULL){
            travel(Node->right,path,result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        vector<int>path;
        if(root==NULL){
            return result;
        }
        travel(root,path,result);
        return result;
    }
};