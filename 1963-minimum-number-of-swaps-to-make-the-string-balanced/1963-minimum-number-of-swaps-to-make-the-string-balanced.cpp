class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&s[i]==']'){
                st.pop();
            }
            else if(s[i]=='['){
                st.push(s[i]);
            }
        }
        int tmp=st.size();
        if(tmp%2==0){
            return tmp/2;
        }
        else{
            return 1+tmp/2;
        }
        return 0;
    }
};