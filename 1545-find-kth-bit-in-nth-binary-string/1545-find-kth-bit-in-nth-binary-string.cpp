class Solution {
public:
    string  invert(string a){
        string b=a;
        for(int i=0;i<a.size();i++){
            if(a[i]=='0'){
                b[i]='1';
            }
            else{
                b[i]='0';
            }
        }
        return b;
    }
    string reverse(string a){
        string c="";
        for(int i=a.size()-1;i>=0;i--){
            c+=a[i];
        }
        return c;
    }
    char findKthBit(int n, int k) {
        vector<string>dp(20);
        dp[0]="0";
        for(int i=1;i<20;i++){
            dp[i]=dp[i-1]+'1'+reverse(invert(dp[i-1]));
        }
        return dp[n-1][k-1];
    }
};