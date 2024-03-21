class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0;i<s.size();i=i+2*k){
            if(s.size()-i>=k){ //剩下的字符比k還多(等)
                reverse(s.begin()+i,s.begin()+i+k);
            }
            else{
                reverse(s.begin()+i,s.end());
            }
        }
        return s;
    }
};