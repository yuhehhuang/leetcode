class Solution {
public:
    string reverseVowels(string s) {
        int tmp_index=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                if(tmp_index==-1){
                    tmp_index=i;
                }
                else{
                    int tmp_swap=s[tmp_index];
                    s[tmp_index]=s[i];
                    s[i]=tmp_swap;
                    tmp_index=i;
                }
            }
        }
        return s;
    }
};