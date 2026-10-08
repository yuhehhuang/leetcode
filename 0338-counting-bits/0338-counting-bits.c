/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int bit_num(int n){
    int cnt=0;
    while(n){
        cnt++;
        n=n&(n-1);
    }
    return cnt;
}
int* countBits(int n, int* returnSize) {
    *returnSize=n+1;
    int* ans=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0;i<=n;++i){
        ans[i]=bit_num(i);
    }
    return ans;
}