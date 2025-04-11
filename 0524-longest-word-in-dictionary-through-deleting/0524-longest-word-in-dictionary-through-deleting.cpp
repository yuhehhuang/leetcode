class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        for(int i=0;i<dictionary.size();++i){
            int j=0,k=0;
            while(k<dictionary[i].length()&&j<s.length()){
                if(s[j]==dictionary[i][k]){
                    k++;
                }
                j++;
            }
            //判斷是否有找到
            if(k==dictionary[i].length()){
                if(ans.length()<dictionary[i].length()){
                    ans=dictionary[i];
                }
                else if(ans.length()==dictionary[i].length()){
                    ans=min(ans,dictionary[i]);
                }
            }
        }
        return ans;
    }
};