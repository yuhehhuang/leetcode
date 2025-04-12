class Solution {
public:
    bool isSubseq(string&s,string&t){
        int i=0;
        for(char c:t){
            if(s[i]==c&&++i==s.length()){
                return true;
            }
        }
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        int ans=-1;
        for(int i=0;i<strs.size();++i){
            if((int)strs[i].length()<=ans){
                continue;
            }
            for(int j=0;j<strs.size();++j){
                if(j!=i&&isSubseq(strs[i],strs[j])){
                    goto next;       
                }
            }
            ans=strs[i].length();
            next:;
        }
        return ans;
    }
};