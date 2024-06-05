class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j] represents the number of distinct subsequences of s[0..i] which equals t[0..j]
        vector<vector<unsigned int>> dp(s.size(), vector<unsigned int>(t.size(), 0));

        // Fill the dp table for the first column
         for(int i=0;i<s.size();i++){
            if(s[i]==t[0]){
                if(i==0){
                    dp[0][0]=1;
                }
                else
                dp[i][0]=dp[i-1][0]+1;
            }
            else{
                if(i==0){
                    continue;
                }
                else dp[i][0]=dp[i-1][0];
            }
        }
        // Fill the dp table for the first row

        // Fill the rest of the dp table
        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[s.size() - 1][t.size() - 1];
    }
};