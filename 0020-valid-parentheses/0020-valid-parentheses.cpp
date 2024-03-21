class Solution {
public:
    bool isValid(string s) {
     stack<char> ans;
     if(s.size()%2==1){
         return false;
     }
     for(int i=0;i<s.size();i++){
         if(s[i]=='('){
             ans.push(')');
         }
         else if(s[i]=='['){
             ans.push(']');
         }
         else if(s[i]=='{'){
             ans.push('}');
         }
         else if(ans.empty()||ans.top()!=s[i]){ //若有CASE都是右括弧這樣我的ANS會是空的 我如果判斷沒有ANS.EMPTY()我的ans.top()!=s[i]根本無法判斷 因為是空的
             return false;
         }
         else{
             ans.pop();
         }
     }
     return ans.empty();   
    }
};