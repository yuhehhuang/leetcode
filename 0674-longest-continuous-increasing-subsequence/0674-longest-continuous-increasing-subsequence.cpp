class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
     vector<int>dp(nums.size(),1);
     int ans=INT_MIN;
     for(int i=1;i<nums.size();i++){
        if(nums[i]>nums[i-1]){
            dp[i]=max(dp[i],dp[i-1]+1);
            ans=max(ans,dp[i]);
        }
     }
     return ans==INT_MIN?1:ans;   
    }
};