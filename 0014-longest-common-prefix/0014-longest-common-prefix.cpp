class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int minLen=INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<minLen){
                minLen=strs[i].size();
            }
        }
        for(int i=0;i<minLen;i++){
            for(int j=0;j<strs.size();j++){
                if(strs[0][i]!=strs[j][i]){
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};