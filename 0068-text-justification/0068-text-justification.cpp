class Solution {
public:
    string join(int start,int end,const string& sep,vector<string>&words){
        string res;
        for(int i=start;i<end;++i){
            if(i>start){
                res+=sep;
            }
            res+=words[i];
        }
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;){
            int start =i ;
            int sum_len =words[i].size();
            for(i=i+1;i<n&&sum_len+words[i].size()+1<=maxWidth;i++){
                sum_len+=words[i].size()+1;
            }
            int extra_spaces=maxWidth-sum_len;
            int gaps= i-start-1; //有幾個空隙
            if(gaps==0||i==n){
                string row = join(start,i," ",words);
                row+=string(extra_spaces,' ');
                ans.push_back(move(row));
                continue;
            }
            int avg=extra_spaces/gaps;
            int rem = extra_spaces%gaps;
            string spaces(avg+1,' ');
            string row=join(start,start+rem+1,spaces+" ",words); //前rem個空隙因為平均完還剩space，所以都多給一個
            row +=spaces;//word[start+rem]跟word[start+rem+1]之間的space
            row+=join(start+rem+1,i,spaces,words);
            ans.push_back(move(row));
        }
        return ans;
    }
};