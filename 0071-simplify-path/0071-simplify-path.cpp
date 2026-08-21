class Solution {
public:
    string simplifyPath(string path) {
        vector<string>ans;
        int i=0,n=path.length();
        for(i=0;i<n;){
            if(path[i]=='/'){
                string word;
                i++;
                while(i<n&&path[i]!='/'){
                    word+=path[i++];
                }
                if(word==".."){
                    if(ans.size()!=0)ans.pop_back();
                    continue;
                }
                else if(word=="."){
                    continue;
                }
                if(word.size()!=0)ans.push_back(word);
            }
        }
        if(ans.size()==0)return "/";
        string ans_1="";
        for(int i=0;i<ans.size();++i){
            ans_1+="/"+ans[i];
        }
        return ans_1;
    }
};