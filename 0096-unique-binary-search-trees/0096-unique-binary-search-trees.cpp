class Solution {
public:
    int numTrees(int n) {
        if(n<=2){
            return n;
        }
        vector<int>dp(20,0);
        //dp[i]=x means 連續的i個數可以排成x種形狀 
        //-->dp[3]:head=1 右邊連續2個數+head=2 左邊連續1個數&右邊連續1個數 head=3 左邊連續2個數
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=i;j>0;j--){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};