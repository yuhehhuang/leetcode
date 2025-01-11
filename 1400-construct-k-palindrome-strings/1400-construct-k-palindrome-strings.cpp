class Solution {
public:
    bool canConstruct(string s, int k) {
        //偶數個=>可以1也可以n個palindrome string 且偶數個可以搭配奇數個的合成一個
        //奇數個=>可n 但不能1個
        int cnt[26]{};
        int tmp=0;
        if(s.length()<k){
            return false;
        }
        for(char c:s){
            cnt[c-'a']++;
        }
        for(int i=0;i<26;++i){
            if(cnt[i]%2==1){
                tmp++;
            }
        }
        if(tmp>k){
            return false;
        }
        return true;
    }
};