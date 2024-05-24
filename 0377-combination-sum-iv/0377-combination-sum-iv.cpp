class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //dp[i]means target=i的組合
        //dp[n]=nums[0]是最後一步湊成n+nums[1]是最後一步湊成n+nums[2]是最後一步湊成n+....+nums[n-1]是湊成最後一步的排列和--->nums是內迴圈
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                if(i >= nums[j] ){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        // 確保返回值不會溢出
        return dp[target] ;
    }
};