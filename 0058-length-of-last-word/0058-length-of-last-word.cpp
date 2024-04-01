class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==1){
            return 1;
        }
        reverse(s.begin(),s.end());
        int count=0;
        int index=0;
        while(s[index]==' '){
            index+=1;
        }
        while(s[index]!=' '&&index<=s.size()-1){
            count++;
            index++;
        }
        return count;
    }
};