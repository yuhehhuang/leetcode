class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int cnt=1;
        int start=0;
        int ans=0;
        for(int i=0;i<word.size()-1;++i){
            if(word[i]<word[i+1]){
                cnt++;
            }
            else if(word[i]>word[i+1]){
                cnt=1;
                start=i+1;
            }
            if(cnt==5){
                ans=max(ans,i-start+2);
            }
        }
        return ans;
    }
};