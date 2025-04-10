class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1,st2;
        for(int i=0;i<s.size();++i){
            if(!st1.empty()&&s[i]=='#'){
                st1.pop();
            }
            else if(s[i]!='#'){
                st1.push(s[i]);
            }
        }
        for(int j=0;j<t.size();++j){
            if(!st2.empty()&&t[j]=='#'){
                st2.pop();
            }
            else if(t[j]!='#'){
                st2.push(t[j]);
            }
        }
        while(!st1.empty()&&!st2.empty()){
            if(st1.top()!=st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
    return st1.empty()&&st2.empty();
    }
};