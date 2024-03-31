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
 TreeNode* traversal (vector<int>& inorder, vector<int>& postorder){
        if(postorder.size()==0) return NULL;
        int rootvalue=postorder[postorder.size()-1];
        TreeNode* root=new TreeNode(rootvalue);
        if(postorder.size()==1) return root;
        int delimeterIndex;
        for(delimeterIndex=0;delimeterIndex<inorder.size();delimeterIndex++){
            if(inorder[delimeterIndex]==rootvalue) break;
        }
        //左閉右開
        vector<int>leftInorder(inorder.begin(),inorder.begin()+delimeterIndex);
        vector<int>rightInorder(inorder.begin()+delimeterIndex+1,inorder.end());
        postorder.resize(postorder.size()-1);
        
        vector<int>leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int>rightPostorder(postorder.begin()+leftInorder.size(),postorder.end());
        root->left=traversal(leftInorder,leftPostorder);
        root->right=traversal(rightInorder,rightPostorder);
        return root;


 }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)return NULL;
        return traversal(inorder,postorder);
    }
};