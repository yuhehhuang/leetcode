class Solution {
public:
    int strStr(string haystack, string needle) {
        int shift_size=haystack.size()-needle.size();
        if(shift_size<0){
            return -1;
        }
        for(int i=0;i<=shift_size;i++){
            if(haystack[i]==needle[0]){
                int j;
                for(j=i;j<i+needle.size();j++){
                    if(haystack[j]!=needle[j-i]){
                        break;
                    }
                }
                if(j==i+needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};