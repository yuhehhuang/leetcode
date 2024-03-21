int climbStairs(int n){
        if(n<=2){
        return n;
    }
    else{
    int *DP = (int*)calloc(n + 1, sizeof(int));
    DP[1]=1;
    DP[2]=2;
    for(int i=3;i<=n;i++){
        DP[i]=DP[i-1]+DP[i-2]; 
        }
    return DP[n];
    }
}