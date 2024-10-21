class Solution {
public:
    int backtrack(int start,string s,unordered_set<string>seen){
        if(start==s.size()){
            return 0;
        }
        int ans=0;
        for(int end=start+1;end<=s.size();++end){
            string substring=s.substr(start,end-start);
            if(seen.find(substring)==seen.end()){
                seen.insert(substring);
                ans=max(ans,1+backtrack(end,s,seen));
                seen.erase(substring);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>seen;
        return backtrack(0,s,seen);
    }
};