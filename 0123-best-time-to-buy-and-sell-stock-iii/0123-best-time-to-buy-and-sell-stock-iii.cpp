class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(5,0));
        dp[0][1]=-prices[0];
        dp[0][2]=0;
        dp[0][3]=-prices[0];
        dp[0][4]=0;
        for(int i=1;i<prices.size();i++){
            dp[i][1]=max(dp[i-1][1],-prices[i]);
            dp[i][2]=max(dp[i-1][2],prices[i]+dp[i-1][1]);
            dp[i][3]=max(dp[i-1][3],dp[i][2]-prices[i]);
            dp[i][4]=max(dp[i-1][4],prices[i]+dp[i-1][3]);
        }
        return dp[prices.size()-1][4];
    }
};