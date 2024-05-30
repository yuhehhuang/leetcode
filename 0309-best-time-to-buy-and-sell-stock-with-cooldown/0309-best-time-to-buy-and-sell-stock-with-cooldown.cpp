class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(4,0));
        //0:持有股票狀態 1:不持有股票狀態 2:今天賣出股票狀態 3:冷凍期狀態
        dp[0][0]=-prices[0];
        for(int i=1;i<prices.size();i++){
            //持有:上一天就持有OR今天購入
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1]-prices[i],dp[i-1][3]-prices[i]));
            dp[i][1]=max(dp[i-1][1],dp[i-1][3]);
            dp[i][2]=dp[i-1][0]+prices[i];
            dp[i][3]=dp[i-1][2];
        }
        return max(dp[prices.size()-1][1],max(dp[prices.size()-1][2],dp[prices.size()-1][3]));
    }
};