class Solution {
public:
    int balancedString(string s) {
        int m=s.length()/4;
        int cnt['X']{};
        for(char c:s)  cnt[c]++;
        if(cnt['Q']==m&&cnt['W']==m&&cnt['E']==m&&cnt['R']==m){
            return 0;
        }
        int ans=s.length();
        int left=0;
        for(int right=0;right<s.length();right++){
            cnt[s[right]]--;
            while(cnt['Q']<=m&&cnt['W']<=m&&cnt['E']<=m&&cnt['R']<=m){
                ans=min(ans,right-left+1);
                ++cnt[s[left++]];
            }
        }
        return ans;
    }
};