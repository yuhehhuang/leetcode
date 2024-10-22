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
bool cmp(long long a,long long b){
    return a>b;
} 
class Solution {
public:
    void bfs(TreeNode* root,queue<TreeNode*>&que,vector<long long>&sum){
        while(!que.empty()){
            int level_size=que.size();
            long long level_sum=0;
            for(int i=0;i<level_size;++i){
                TreeNode* node=que.front();
                que.pop();
                level_sum+=node->val;
                if(node->right!=NULL){
                    que.push(node->right);
                }
                if(node->left!=NULL){
                    que.push(node->left);
                }
            }
            sum.push_back(level_sum);
        }

    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>que;
        que.push(root);
        vector<long long>sum;
        bfs(root,que,sum);
        sort(sum.begin(),sum.end(),cmp);
        if(sum.size()<k){
            return -1;
        }
        return sum[k-1];
    }
};