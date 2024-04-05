class Solution {
public:
/*Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
從這個example可知不能用for()遍歷發現bB刪除然後Ac比，而是又有aA因為bB不見也要一起刪除----->stack特性*/
    string makeGood(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(!st.empty()&&abs(s[i]-st.top())==32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};