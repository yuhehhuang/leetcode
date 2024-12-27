class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n=s.size();
        unordered_map<string,int>mp;
        int ans=0;
        for(int i=0;i<=n-minSize;++i){
            string tmp=s.substr(i,minSize);
            unordered_set<char> check(tmp.begin(),tmp.end());
            if(check.size()<=maxLetters){
                mp[tmp]++;
                ans=max(ans,mp[tmp]);
            }
        }
        return ans;
    }
};