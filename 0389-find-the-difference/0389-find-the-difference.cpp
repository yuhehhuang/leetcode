class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        if(s.size()<t.size()){
            //to certain |s| >|t| 讓我第一個for loop當作紀錄最長的
            swap(s,t);
        }
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
        }
        for(unordered_map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
            if(it->second>0){
                return it->first;
            }
        }
        return 0;
    }
};