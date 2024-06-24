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
        queue<TreeNode*>que;
        vector<vector<int>>result;
        if(root!=NULL){
            que.push(root);
        }
        while(!que.empty()){
            vector<int>row;
            int size=que.size();
            for(int i=0;i<size;i++){
                //蒐集本層輸入進路徑(ROW)
                row.push_back(que.front()->val);
                //以下蒐集下一輪的data
                if(que.front()->left!=NULL){
                    que.push(que.front()->left);
                }
                if(que.front()->right!=NULL){
                    que.push(que.front()->right);
                }
                que.pop();
            }
            result.push_back(row);
        }
        return result;
    }
};