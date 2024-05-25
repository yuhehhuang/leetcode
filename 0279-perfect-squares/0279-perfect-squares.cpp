class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int j=0;j<n+1;j++){
            for(int i=1;i*i<=n;i++){
                if(j>=i*i){
                    dp[j]=min(dp[j-i*i]+1,dp[j]);
                }
            }
        }
        return dp[n];
    }
};