class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        vector<int>dp(m+1,0);
//        for(int j=0;j<=m;++j){
            //dp[0][j]=j;
        //}
        //for(int i=0;i<=n;++i){
            //dp[i][0]=i;
        //}
        for(int i=0;i<n;++i){
            int prev=i;
            //prev=dp[i][0];
            dp[0]++;
            for(int j=0;j<m;++j){
                int tmp=dp[j+1];
                if(word1[i]==word2[j]){
                    //dp[i+1][j+1]=dp[i][j];
                    dp[j+1]=prev;
                }
                else{
                    //dp[i+1][j+1]=min(min(dp[i+1][j],dp[i][j+1]),dp[i][j])+1;
                    dp[j+1]=min(min(dp[j],dp[j+1]),prev)+1;
                }
                prev=tmp;
            }
        }
        return dp[m];    
    }
};