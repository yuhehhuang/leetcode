class Solution {
    string mapping[10]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return{};
        }
        vector<string>ans;
        int n=digits.length();
        string path(n,0);
        auto dfs=[&](auto&&dfs,int i){
            if(i==n){
                ans.push_back(path);
                return;
            }
            for(char c : mapping[digits[i] - '0']){
                path[i]=c;
                dfs(dfs,i+1);
            }
        };
        dfs(dfs,0);
        return ans;
        
    }
};