class Solution {
public:
    int minDistance(string word1, string word2) {
        //ans =word1.size()+word2.size()-LCS
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        //dp[i][j] means word1:index0~i-1 word2:index0~j-1的LCS
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return word1.size()+word2.size()-2*dp[word1.size()][word2.size()];
    }
};