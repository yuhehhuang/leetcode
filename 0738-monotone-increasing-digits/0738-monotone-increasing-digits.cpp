class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        int flag=s.size();
        for(int i=s.size()-1;i>0;i--){
            if(s[i-1]>s[i]){
                s[i-1]--;
                flag=i;
            }
        }
        for(int i=flag;i<s.length();i++){
            s[i]='9';
        }
        n=stoi(s);
        return n;
    }
};