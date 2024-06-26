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
    TreeNode* traversal(vector<int>&nums){
        if(nums.size()==1){
            TreeNode* leaf=new TreeNode(nums[0]);
            return leaf;
        }
        int slice_index=nums.size()/2;
        TreeNode* root=new TreeNode(nums[slice_index]);
        vector<int>left(nums.begin(),nums.begin()+slice_index);
        vector<int>right(nums.begin()+slice_index+1,nums.end());
        root->left=sortedArrayToBST(left);
        root->right=sortedArrayToBST(right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        return traversal(nums);
    }
};