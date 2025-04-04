class Solution {
public:
    bool check(string &s,string &w){
        if(w.size()>s.size()||s[0]!=w[0]){
            return false;
        }
        int i=0,j=0,len1=w.size(),len2=s.size();
        while(j<len2){
            if(w[i]==s[j]){
                i++;
                j++;
            }
            else{
                int k=j;
                int cnt=1;
                while(k>0&&s[k]==s[k-1]){
                    k--;
                    cnt++;
                }
                k=j;
                while(k<len2-1&&s[k]==s[k+1]){
                    k++;
                    cnt++;
                }
                if(cnt<3){
                    return false;
                }
                j=k+1;
                if(w[i]!=s[j]) return false;
            }
        }
        return i==len1;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();++i){
            ans+=check(s,words[i]);
        }

        return ans;
    }
};