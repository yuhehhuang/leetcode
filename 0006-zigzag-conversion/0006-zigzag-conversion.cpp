class Solution {
public:
    string convert(string s, int numRows) {
        int flag=0;
        int len=s.length();
        int i=0;
        vector<string>zigzag(numRows,"");
        int now=0,ceil=0,floor=numRows-1;
        if(numRows==1){
            return s;
        }
        while(len--){
            if(!flag){
                zigzag[now++]+=s[i++];
                if(now==floor+1){
                    flag=1;
                    now=floor-1;
                }
            }
            else{
                zigzag[now--]+=s[i++];
                if(now==-1){
                    flag=0;
                    now=ceil+1;
                }
            }
        }
        string ans="";
        for(int i=0;i<numRows;++i){
            for(char c: zigzag[i]){
                ans+=c;
            }
        }
        return ans;
    }
};