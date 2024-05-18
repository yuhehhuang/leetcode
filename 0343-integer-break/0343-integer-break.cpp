class Solution {
public:
//dp[x] means that :x若要切割的話 最大的product value;
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],max(dp[i-j]*j,(i-j)*j));
            }
        }
        return dp[n];
        
    }
};