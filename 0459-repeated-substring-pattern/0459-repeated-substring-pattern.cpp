class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        for(int i=1;i<=len/2;i++){
            if(len%i!=0){
                continue;
            }
            int count=len/i;
            string compare="";
            string segment=s.substr(0,i);
            while(count--){
                compare+=segment;
            }
            if(s.compare(compare)==0){
                return true;
            }
        }
        return false;
    }
};