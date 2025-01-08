class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int cnt[26];
        int left=0;
        int ans=0;
        int big=0;
        for(int right=0;right<s.length();++right){
            cnt[s[right]-'a']++;
            while(cnt[s[right]-'a']>=k){
                cnt[s[left++]-'a']--;
            }
            ans+=left;
        }
        return ans;

    }
};