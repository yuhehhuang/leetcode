class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        bool pair=false;
        int ans=0;
        int left=0;
        for(int right=0;right<s.size();++right){
            while(right>0&&pair==true&&s[right]==s[right-1]){
                if(s[left]==s[left+1]){
                    pair=false;
                }
                left++;
            }
            if(right>0&&pair==false&&s[right]==s[right-1]){
                pair=true;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};