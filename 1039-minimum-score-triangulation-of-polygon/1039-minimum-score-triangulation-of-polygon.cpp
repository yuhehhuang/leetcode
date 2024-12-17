class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        //k>i且k要先有 所以for i要遞減
        //k<j且k要先有 所以for j要遞增
        // dp[i][j]=min(dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
        //dfs(i,j)=min,k,(dfs(i,k)+dfs(k,j)+v[i]*v[j]*v[k];)
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-3;i>=0;--i){
            for(int j=i+2;j<n;++j){
                int ans=INT_MAX;
                for(int k=i+1;k<j;++k){
                    ans=min(ans,dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
    }
};