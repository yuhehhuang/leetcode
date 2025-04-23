class Solution {
public:
    int countHomogenous(string s) {
        long long ans=0;
        const int MOD = 1000000007;
        int i=0;
        while(i<s.length()){
            int len=1;
            while(i<s.length()-1&&s[i]==s[i+1]){
                i++;
                len++;
            }
            ans = (ans +1ll*len * (len + 1) / 2) % (MOD);
            i++;
        }
        return ans;
    }
};