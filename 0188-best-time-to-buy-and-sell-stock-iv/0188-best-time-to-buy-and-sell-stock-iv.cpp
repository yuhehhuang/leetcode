class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //k要有0~2*k(total:2K+1)個狀態表示
        vector<vector<int>>dp(prices.size(),vector<int>(2*k+1,0));
        for(int j=1;j<2*k;j+=2){
            dp[0][j]=-prices[0];
        }
        for(int i=1;i<prices.size();i++){
            for(int j=1;j<2*k;j+=2){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]-prices[i]);
                dp[i][j+1]=max(dp[i-1][j+1],dp[i-1][j]+prices[i]);
            }
        }
        return dp[prices.size()-1][2*k];
    }
};