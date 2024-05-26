class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            for(int j=0;j<i-1;j++){
                dp[i]=max(dp[j]+nums[i],dp[i]);
            }
        }
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
};