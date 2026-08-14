class Solution {
public:
    string longestPalindrome(string s) {
        //O(n^2)有 
        string ans;
        pair<int,int>p{0,0};
        int max_len=0;
        for(int i=0;i<s.length();++i){
            for(int j=s.length()-1;j>=i;j--){
                int left=i;
                int right=j;
                bool valid=true;
                while(left<=right){
                    if(s[left++]!=s[right--]){
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    int len=j-i+1;
                    if(len>max_len){
                        max_len=j-i+1;
                        p={j,i};
                    }
                    break;
                }
            }
        }
        for(int k=p.second;k<=p.first;k++){
            ans+=s[k];
        }
        return ans;
    }
};