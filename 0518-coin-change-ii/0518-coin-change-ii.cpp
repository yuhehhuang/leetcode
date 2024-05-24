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
                    //dp[i][j]=至少有一個coins[i]的方式組成背包(dp[i][j-coins[i]])+都沒有coins[i]的方式湊成背包(dp[i-1][j])
//If we want to make change for N cents, and we have infinite supply of each of {S = S_1, S_2, ..., S_m} valued coins.
//The set of solutions for this problem, C(N,m), can be partitioned into two sets.
//There are those sets that do not contain any S_m and
//Those sets that contain at least 1 S_m
//Then we get recurence relation.
//C(N, m) = C(N, m-1) + C(N - S_m, m)///////////
                    dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j];
                }
            }
        }
        return dp[coins.size()-1][amount];
    }
};