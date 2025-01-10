class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int real_cnt[26]{};
        for(string s:words2){
            int cnt[26];
            for(int i=0;i<s.length();++i){
                cnt[s[i]-'a']++;
            }
            for(int i=0;i<26;++i){
                real_cnt[i]=max(real_cnt[i],cnt[i]);
            }
        }
        vector<string>ans;
        for(string s:words1){
            int word1_cnt[26]{};
            for(int i=0;i<s.length();++i){
                word1_cnt[s[i]-'a']++;
            }
            bool check=false;
            for(int i=0;i<26;++i){
                if(real_cnt[i]>word1_cnt[i]){
                    check=true;
                    break;
                }
            }
            if(!check){
                ans.push_back(s);
            }
        }
        return ans;

    }
};