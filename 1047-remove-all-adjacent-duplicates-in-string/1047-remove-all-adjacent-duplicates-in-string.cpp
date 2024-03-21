class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ans;
        stack<char> tmp;
        string finale_ans;
        for(int i=0;i<s.size();i++){
            if(!ans.empty()&&ans.top()==s[i]){
                ans.pop();
            }
            else{
                ans.push(s[i]);
            }
        }
        while(!ans.empty()){
            tmp.push(ans.top());
            ans.pop();
        }
        while(!tmp.empty()){
            finale_ans+=tmp.top();
            tmp.pop();
        }
        return finale_ans;
    }
};