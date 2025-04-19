class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=INT_MIN;
        for(int i=0;i<s.length();++i){
            int cnt=1;
            int left=i;
            int right=i+1;
            while(right<s.length()&&s[right]-s[left]==1){
                right++;
                left++;
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};