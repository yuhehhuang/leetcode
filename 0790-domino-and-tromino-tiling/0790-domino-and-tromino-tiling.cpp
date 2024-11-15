class Solution {
public:
const int MOD = 1e9 + 7;
    int numTilings(int n) {
        if(n==1){
            return 1;
        }
        long f[n+1];
        f[0]=f[1]=1;
        f[2]=2;
        for(int i=3;i<=n;++i){
            f[i]=(2*f[i-1]+f[i-3])%MOD;
        }
        return f[n];
    }
};