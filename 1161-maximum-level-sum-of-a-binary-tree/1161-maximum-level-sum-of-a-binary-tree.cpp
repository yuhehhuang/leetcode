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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>que;
        int level=0;
        int level_number;
        int max=INT_MIN;
        if(root!=NULL){
            que.push(root);
        }
        while(!que.empty()){
            int size=que.size();
            level++;
            int sum=0;
            for(int i=0;i<size;i++){
                TreeNode* tmp=que.front();
                que.pop();
                sum+=tmp->val;
                if(tmp->left!=NULL){
                    que.push(tmp->left);
                }
                if(tmp->right!=NULL){
                    que.push(tmp->right);
                }
            }
            if(sum>max){
                max=sum;
                level_number=level;
            }
        }
        return level_number;
    }    
};