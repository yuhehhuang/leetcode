class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>s1_freq(26,0);
        vector<int>s2_freq(26,0);
        int window_len=s1.size();
        if(s1.size()>s2.size()){
            return false;
        }
        //紀錄s1出現的char頻率
        for(int i=0;i<s1.size();i++){
            s1_freq[s1[i]-'a']++;
        }
        //紀錄s2從0~s1.size()-1出現的char頻率
        for(int i=0;i<s1.size();i++){
            s2_freq[s2[i]-'a']++;
        }
        for(int i=0;i<s2.size()-window_len;i++){
            if(s1_freq==s2_freq){
                return true;
            }
            s2_freq[s2[i]-'a']--;
            s2_freq[s2[i+window_len]-'a']++;
        }
        return s1_freq==s2_freq;
    }
};