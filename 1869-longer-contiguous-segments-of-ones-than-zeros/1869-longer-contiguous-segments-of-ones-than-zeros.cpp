class Solution {
public:
    bool checkZeroOnes(string s) {
        int max_zero=0;
        int max_one=0;
        int i=0;
        while(i<s.length()){
            char ch=s[i];
            int len=0;
            while(i<s.length()&&s[i]==ch){
                len++;
                i++;
            }
            if(ch=='0'){
                max_zero=max(max_zero,len);
            }
            else{
                max_one=max(max_one,len);
            }
        }
        return max_one>max_zero;
    }
};