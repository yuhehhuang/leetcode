class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>dp(nums.size(),1);//(左到右)product of 0~i-1,dp[i]=dp[i-1]*nums[i-1]
        vector<int>dp2(nums.size(),1);//(右到左)product of n~i+1 dp2[i]=dp[i+1]*nums[i+1]
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            dp[i]=dp[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            dp2[i]=dp2[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(dp[i]*dp2[i]);
        }
        return ans;
    }
};