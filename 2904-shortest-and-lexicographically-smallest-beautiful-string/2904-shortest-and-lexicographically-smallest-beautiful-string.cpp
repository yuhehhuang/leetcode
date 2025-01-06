class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        for(int i=0;i<s.length();++i){
            int cnt=0;
            for(int j=i;j<s.length();++j){
                if(s[j]=='1'){
                    cnt++;
                }
                if(cnt==k){
                    if(ans.empty()||ans.length()>=j-i+1){
                        if(ans.length()==j-i+1){
                            ans=ans<s.substr(i,j-i+1)?ans:s.substr(i,j-i+1);
                        }
                        else{
                            ans=s.substr(i,j-i+1);
                        }
                    break;
                    }
                }
            }
        }
        return ans;
    }
};