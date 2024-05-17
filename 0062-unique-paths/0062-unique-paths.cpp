class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1&&m==1){
            return 1;
        }
        vector<vector<int>>dp(m,vector<int>(n,0));
        //dp[1][0]=1;
        //dp[0][1]=1;
        for(int i=1;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<n;j++){
            dp[0][j]=1;
        }
        //column first
        for(int j=1;j<n;j++){
            for(int i=1;i<m;i++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};