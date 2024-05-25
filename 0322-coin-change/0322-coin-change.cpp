class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //min....
        //dp[i][j]=不花coins[i]的解and有花coins[i]的解去最小
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,amount+1));
        for(int i=0;i<coins.size();i++){
            dp[i][0]=0;
        }
        for(int j=1;j<amount+1;j++){
            if(j%coins[0]==0){
                dp[0][j]=j/coins[0];
            }
        }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i]<=j){
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
                }
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[coins.size()-1][amount]==amount+1?-1:dp[coins.size()-1][amount];
    }
};