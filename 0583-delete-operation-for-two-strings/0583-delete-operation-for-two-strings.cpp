class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),0));
        for(int i=0;i<word1.size();i++){
            if(word1[i]==word2[0]){
                dp[i][0]=1;
            }
            else{
                if(i==0) continue;
                else
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int j=1;j<word2.size();j++){
            if(word1[0]==word2[j]) dp[0][j]=1;
            else{
                dp[0][j]=dp[0][j-1];
            }
        }
        for(int i=1;i<word1.size();i++){
            for(int j=1;j<word2.size();j++){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return word1.size()+word2.size()-2*dp[word1.size()-1][word2.size()-1];
    }
};