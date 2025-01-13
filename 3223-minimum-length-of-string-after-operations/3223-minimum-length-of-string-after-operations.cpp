class Solution {
public:
    int minimumLength(string s) {
        int cnt[26]{};
        int ans=0;
        for(int i=0;i<s.length();++i){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<=25;++i){
            if(cnt[i]>=2&&cnt[i]%2==1){
                ans+=1;
            }
            else if(cnt[i]>=2&&cnt[i]%2==0){
                ans+=2;
            }
            else{
                ans+=cnt[i];
            }
        }
        return ans;
    }
};