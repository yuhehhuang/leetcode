class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        unordered_map<char,int>copy;
        if(s2.size()<s1.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        for(int i=0;i<=s2.size()-s1.size();i++){
            if(mp.find(s2[i])!=mp.end()){
                copy=mp;
                for(int j=i;j<i+s1.size();j++){
                    if(copy.find(s2[j])!=copy.end()){
                        if(copy[s2[j]]>1){
                            copy[s2[j]]--;
                        }
                        else{
                            copy.erase(s2[j]);
                        }
                    }
                    else{
                        break;
                    }
                }
                if(copy.empty()){
                    return true;
                }
            }
        }
        return false;
    }
};