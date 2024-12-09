class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int m=n*2;
        vector<string>ans;
        string path(m,0);
        auto dfs=[&](auto&&dfs,int i,int open){
            if(i==m){
                ans.push_back(path);
                return;
            }
            if(open<n){
                path[i]='(';
                dfs(dfs,i+1,open+1);
            }
            if(open>i-open){
                //每個index 看左邊有的左括號要比右括號多，否則違法
                path[i]=')';
                dfs(dfs,i+1,open);
            }
        };
        dfs(dfs,0,0);
        return ans;
    }
};