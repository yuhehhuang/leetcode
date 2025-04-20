class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int i=0;
        while(i<s.length()){
            int len=1;
            while(i<s.length()-1&&s[i]==s[i+1]){
                i++;
                len++;
            }
            if(len==k){
                return true;
            }
            i++;
        }
        return false;
    }
};