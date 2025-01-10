class Solution {
public:
    bool is_valid(int cnt_w1[],int cnt_w2[]){
        for(char i='a';i<='z';++i){
            if(cnt_w1[i-'a']<cnt_w2[i-'a']){
                return false;
            }
        }
        return true;
    }
    long long validSubstringCount(string word1, string word2) {
        int cnt_w1[26]{};
        int cnt_w2[26]{};
        int left=0;
        long long ans=0;
        for(int i=0;i<word2.length();++i){
            cnt_w2[word2[i]-'a']++;
        }
        for(int right=0;right<word1.size();++right){
            cnt_w1[word1[right]-'a']++;
            while(is_valid(cnt_w1,cnt_w2)){
             cnt_w1[word1[left++]-'a']--;   
            }
            ans+=left;
        }
        return ans;
    }
};