class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                string curr_st="";
                while(st.top()!='['){
                    curr_st=st.top()+curr_st;
                    st.pop();
                }
                st.pop();
                string number="";
                while(!st.empty()&&isdigit(st.top())){
                    number=st.top()+number;
                    st.pop();
                }
                int k_times=stoi(number);
                while(k_times){
                    for(int i=0;i<curr_st.size();++i){
                        st.push(curr_st[i]);
                    }
                    k_times--;
                }  
            }
        }
        s="";
        while(!st.empty()){
                s=st.top()+s;
                st.pop();
        }
        return s;
    }
};