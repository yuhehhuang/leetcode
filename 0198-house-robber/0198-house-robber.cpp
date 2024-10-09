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
            //index 0~i的房子最多能偷的錢==dp[i]
            //dp[i]=(不偷第i家的解 OR 偷第i家的解取)max
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};