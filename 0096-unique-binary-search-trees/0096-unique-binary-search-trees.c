int numTrees(int n) {
    int dp[20]={0};
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=19;++i){
        for(int j=i;j>0;j--){
            //當root是j 那左子樹有j-1個 右子樹要有i-(j+1)+1個=i-j個
            //root j 可以是1~i;
            dp[i] += dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}