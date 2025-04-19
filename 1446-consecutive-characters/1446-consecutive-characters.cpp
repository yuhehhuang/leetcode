class Solution {
public:
    int maxPower(string s) {
        int ans=INT_MIN;
        for(int i=0;i<s.length();++i){
            int len=1;
            while(i>0&&s[i]==s[i-1]){
                len++;
                i++;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};