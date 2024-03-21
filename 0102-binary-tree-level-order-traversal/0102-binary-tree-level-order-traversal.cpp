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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tp;
        vector<vector<int>>result;
        if(root!=NULL){
            tp.push(root);
        }
        while(!tp.empty()){
            vector<int>vec;
            int size=tp.size();
            for(int i=0;i<size;i++){
                TreeNode* node=tp.front();
                tp.pop();
                vec.push_back(node->val);
                if(node->left){
                    tp.push(node->left);
                }
                if(node->right){
                    tp.push(node->right);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};