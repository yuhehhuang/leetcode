class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>que;
        int ans;
        for(int i=0;i<nums.size();++i){
            que.push(nums[i]);
        }
        while(k--){
            ans= que.top();
            que.pop();
        }
        return ans;
    }
};