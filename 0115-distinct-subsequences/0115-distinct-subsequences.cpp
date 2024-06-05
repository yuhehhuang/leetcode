class Solution {
public:
    int numDistinct(string s, string t) {
        //dp[i][j]: s:前i個(index:0~i)字母 符合 t:前j個字母的組合
        //類似背包
        vector<vector<unsigned int>>dp(s.size()+1,vector<unsigned int>(t.size()+1,0));
        for(int i=0;i<s.size();i++){
            dp[i][0]=1;//都不拿
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};