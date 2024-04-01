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
TreeNode* traversal (vector<int>& preorder, vector<int>& inorder){
       if(preorder.size()==0){
            return NULL;
        }
        int treenodevalue=preorder[0];
        TreeNode* root= new TreeNode(treenodevalue);
        if(preorder.size()==1){
            return root;
        }
        int delimeterIndex;
        for(delimeterIndex=0;delimeterIndex<inorder.size();delimeterIndex++){
            if(inorder[delimeterIndex]==treenodevalue) break;
        }
        vector<int>leftInorder(inorder.begin(),inorder.begin()+delimeterIndex);
        vector<int>rightInorder(inorder.begin()+delimeterIndex+1,inorder.end());
        preorder.erase(preorder.begin());
        
        vector<int>leftPreorder(preorder.begin(),preorder.begin()+leftInorder.size());
        vector<int>rightPostorder(preorder.begin()+leftInorder.size(),preorder.end());

        root->left=traversal(leftPreorder,leftInorder);
        root->right=traversal(rightPostorder,rightInorder);
        return root;
    }    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return NULL;
        return traversal(preorder,inorder);
    }
};