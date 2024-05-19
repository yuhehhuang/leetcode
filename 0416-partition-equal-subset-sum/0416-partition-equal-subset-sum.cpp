class Solution {
public:
//题目中物品是nums[i]，重量是nums[i]，价值也是nums[i]，背包体积是sum/2
    bool canPartition(vector<int>& nums) {
        vector<int>dp(10001,0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        sum=sum/2;
        for(int i=0;i<nums.size();i++){
            for(int j=sum;j>=nums[i];j--){
                //若背包體積比第i個物品的重量還小表示不可能購買物品i
                //故背包體積為j時購買[0,i]的最佳解=背包體積為j時購買[0,i-1]是一樣的 所以就不用特地去做覆蓋(更新)
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[sum]==sum){
            return true;
        }
        return false;
    }
};
