class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> ans;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int tmp1=ans.top();
                ans.pop();
                int tmp2=ans.top();
                ans.pop();
                if(tokens[i]=="+"){
                    ans.push(tmp2+tmp1);
                }
                if(tokens[i]=="-"){
                    ans.push(tmp2-tmp1);
                }
                if(tokens[i]=="*"){
                    ans.push(tmp2*tmp1);
                }
                if(tokens[i]=="/"){
                    ans.push(tmp2/tmp1);
                }                                
            }
            else{
                ans.push(stoll(tokens[i]));
            }


        }

        return ans.top();
    }
};