class Solution {
public:
    int majorityElement(vector<int>& nums) { 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[floor(n/2)];
        return ans;
    }
};