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
    static bool cmp(int a,int b){
        return a>b;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        //BFS
        if(root==NULL){
            return {}; 
        }
        queue<TreeNode*>que;
        que.push(root);
        vector<int>ans;
        while(!que.empty()){
            int que_size=que.size();
            vector<int>vec;
            for(int i=0;i<que_size;++i){
                TreeNode* tmp=que.front();
                vec.push_back(tmp->val);
                que.pop();
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
            }
            sort(vec.begin(),vec.end(),cmp);
            ans.push_back(vec[0]);
        }
        return ans;
    }
};