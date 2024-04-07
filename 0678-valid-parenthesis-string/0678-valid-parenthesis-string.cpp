class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st1; //放'(' index
        stack<int>st2; //放'*' index
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st1.push(i);
            }
            else if(s[i]==')'){
                if(!st1.empty()){
                    st1.pop();
                }
                else if(!st2.empty()){
                    st2.pop();
                }
                else{
                    return false;
                }
            }
            else {
                st2.push(i);
            }
        }
        //for loop若走完都沒結束表示順利處理完')'比'('多的case
        //以下是處理'('比 ' )'的case
        while(!st1.empty()&&!st2.empty()){
            if(st2.top()>st1.top()){
            st1.pop();
            st2.pop();
            }
            else{
                return false;
            }
        }
        //while loop走完後 若!st1.empty()==True那表示'*'數不足以處理多出來的'('
        if(!st1.empty()){
            return false;
        }
        return true;
    }
};