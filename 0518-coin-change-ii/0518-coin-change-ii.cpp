class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        //dp[i][j]:coins可以選第0~i的情況下 背包大小為j 這樣的組合數
        for(int i=0;i<coins.size();i++){
            dp[i][0]=1;
            //要滿足背包大小為0的都是不選(不選是一種組合)
        }
        for(int j=coins[0];j<amount+1;j++){
            //處理第0-index的結果
            dp[0][j]+=dp[0][j-coins[0]];
        }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i]){
                    //coin[i]放不進背包 不變
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    //選coins[i]當最後一步的組合+(選coins[0] coins[1] .... coins[i-1]當最後一步的組合-->這些組合湊成j也表示不需要用到coins[i])
                    dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
                }
            }
        }
        return dp[coins.size()-1][amount];
    }
};