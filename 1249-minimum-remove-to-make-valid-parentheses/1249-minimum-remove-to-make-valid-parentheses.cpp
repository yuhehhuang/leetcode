class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else{
                    s.erase(i,1);
                    i--;//少一個char所以i以後的char都往左移一格(index-1) 所以下輪要找的是同一個index hence i-1後i+1=i
                }
            }
        }
        //'('放入stack前')'造成的index改變已經處理過了且放入stack後 後面的')'造成的index影響不會')'之前的那些數值的index(也就是說已經放入stack的')'不受其影響)，故不用怕st內存的index因為')'改變index產生錯誤
        while(!st.empty()){//把多餘'('刪掉
        s.erase(st.top(),1);
        st.pop();
        }
        return s;
    }
};