class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp[i][j] index:0~i in text1 與 index:0~j in text2的output
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};