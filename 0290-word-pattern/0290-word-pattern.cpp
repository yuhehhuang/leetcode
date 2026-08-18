class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        vector<string>vec;
        int start=0;
        for(int i=0;i<s.length();++i){
            if(s[i]==' '){
                vec.push_back(s.substr(start,i-start));
                start=i+1;
            }
        }
        vec.push_back(s.substr(start,s.length()-start));
        if(pattern.size()!=vec.size()) return false;
        for(int i=0;i<pattern.size();++i){
            if(mp1.find(pattern[i])==mp1.end()){
                mp1[pattern[i]]=vec[i];
            }
            else if(mp1[pattern[i]]!=vec[i]){
                return false;
            }
        }
        for(int j=0;j<vec.size();++j){
            if(mp2.find(vec[j])==mp2.end()){
                mp2[vec[j]]=pattern[j];
            }
            else if(mp2[vec[j]]!=pattern[j]){
                return false;
            }
        }
        return true;
    }
};