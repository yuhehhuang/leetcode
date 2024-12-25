class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>set;
        if(k>s.length()){
            return false;
        }
        string t = s.substr(0, k);
        set.insert(t);
        for(int i=k;i<s.length();++i){
            t.erase(0,1);
            t+=s[i];
            set.insert(t);
        }
        return set.size()==(1<<k);
    }
};