class Solution {
public:
    string makeFancyString(string s) {
        int i=0;
        while(i<s.length()){
            int left=i;
            while(i<s.length()-1&&s[i]==s[i+1]){
                i++;
            }
            //
            int len=i-left+1;
            if(len>=3){
                s.erase(left,len-2);
            }
            i++;
        }
        return s;
    }
};