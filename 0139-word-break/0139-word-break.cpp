class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for(int i=1;i<=s.size();i++){ //i:背包大小
            for(int j=0;j<i;j++){
                string word=s.substr(j,i-j);
                if(wordSet.find(word)!=wordSet.end()&&dp[j]==true){
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];
    }
};