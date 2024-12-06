class Solution {
public:
    bool ispalindrome(string& s,int left,int right){
        while(left<right){
            if(s[left++]!=s[right--]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        auto dfs=[&](auto&& self,int start){
            if(start==s.size()){
                ans.push_back(path);
                return;
            }
            for(int i=start;i<s.size();++i){
                if(ispalindrome(s,start,i)){
                    path.push_back(s.substr(start,i-start+1));
                    self(self,i+1);
                    path.pop_back();
                }
            }
        };
        dfs(dfs,0);
        return ans;
    }
};