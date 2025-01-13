class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for(char c:s){
            if(c>='a'&&c<='z'){
                tmp+=c;
            }
            else if(c>='A'&&c<='Z'){
                tmp+=(c+32);
            }
            else if(c>='0'&&c<='9'){
                tmp+=c;
            }
        }
        int left=0;
        int right=tmp.length()-1;
        while(left<=right){
            if(tmp[left++]!=tmp[right--]){
                return false;
            }
        }
        return true;
    }
};