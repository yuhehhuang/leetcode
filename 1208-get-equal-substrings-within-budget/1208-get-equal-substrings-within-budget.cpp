class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0;
        int ans=INT_MIN;
        for(int right=0;right<s.size();++right){
            maxCost-=abs(s[right]-t[right]);
            while(maxCost<0){
                maxCost+=abs(s[left]-t[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};