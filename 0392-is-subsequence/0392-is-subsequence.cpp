class Solution {
public:
    bool isSubsequence(string s, string t) {
          //dp[i][j]:s的index0~i-1與t的index0~j-1的最佳解(不是指定結尾是i-1andj-1的最長解)
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    if(dp[s.size()][t.size()]==s.size()){
        return true;
    }
    else{
        return false;
    }  
    }
};