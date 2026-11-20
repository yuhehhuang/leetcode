
int countPrimes(int n) {
    if(n<=1){
        return 0;
    }
    int cnt =0;
    bool *prime = (bool*)malloc(sizeof(bool)*n);
    memset(prime,true,n*sizeof(bool));
    for(long long i=2;i<n;++i){
        if(prime[i]){
                cnt++;
                for(long long k=i*i;k<n;k+=i){
                    prime[k]=false;
                }
        }
    }
    free(prime);
    return cnt;
}