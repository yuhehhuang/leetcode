class Solution {
public:
    int minDistance(string word1, string word2) {
        //初始化
        if(word1.size()==0&&word2.size()==0)return 0;
        if(word1.size()==0||word2.size()==0){
            return word1.size()==0?word2.size():word1.size();
        }
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),0));
        for(int i=0;i<word1.size();i++){
            if(word1[i]==word2[0]){
                dp[i][0]=i;
            }
            else{
                if(i==0){
                    dp[0][0]=1;
                }
                else{
                    dp[i][0]=dp[i-1][0]+1;
                }
            }
        }
        for(int j=1;j<word2.size();j++){
            if(word1[0]==word2[j]){
                dp[0][j]=j;
            }
            else{
                dp[0][j]=dp[0][j-1]+1;
            }
        }
        for(int i=1;i<word1.size();i++){
            for(int j=1;j<word2.size();j++){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    //replace delete word1 or delete word2
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[word1.size()-1][word2.size()-1];
    }
};