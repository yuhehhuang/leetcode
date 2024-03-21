class Solution {
public:
    void removeExtraSpaces(string& s){ //用來把多餘的space移除
            int slow=0;
            for(int fast=0;fast<s.size();fast++){
                if(s[fast]!=' '){
                    if(slow!=0){
                        s[slow++]=' ';
                    }
                    while(fast<s.size()&&s[fast]!=' '){
                        s[slow++]=s[fast++];
                    }
                }
            }
            s.resize(slow);
        }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s.begin(),s.end());
        string::iterator start=s.begin();
        for(int i=0;i<=s.size();i++){
            if(i==s.size()||s[i]==' '){
                reverse(start,s.begin()+i);
                start=s.begin()+i+1;
            }
        }
        return s;
    }
};

