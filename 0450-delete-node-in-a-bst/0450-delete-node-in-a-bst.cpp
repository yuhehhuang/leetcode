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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //case 1 :key找不到
        if(root==NULL){
            return NULL;
        }
        //case2~5找到key
        if(root->val==key){
            //case2:key是leaf node;
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            //case3:key有左子無右子
            else if(root->left!=NULL&&root->right==NULL){
                TreeNode* tmp=root->left;
                delete root;
                return tmp;
            }
            //case4:key無左子有右子
            else if(root->right!=NULL&&root->left==NULL){
                TreeNode* tmp=root->right;
                delete root;
                return tmp;
            }
            //case5:key有左有右子-->BST結構有變化(這裡會把左子樹接到右子樹最左的下面)
            else{
                TreeNode* cur=root->right;
                while(cur->left!=NULL){
                    cur=cur->left;
                }
                cur->left=root->left;
                TreeNode* tmp=root;
                root=root->right;
                delete tmp;
                return root;
            }
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        return root;

    }
};