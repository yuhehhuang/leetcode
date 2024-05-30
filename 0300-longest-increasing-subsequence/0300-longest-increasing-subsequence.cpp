class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        vector<int>dp(nums.size(),1);
        int ans=INT_MIN;
      for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i])
            dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
        }
      }
      return ans;  
    }
};