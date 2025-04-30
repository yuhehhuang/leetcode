class Solution {
public:
    int function(string &a){
        int cnt[26]={0};
        for(int i=0;i<a.length();++i){
            cnt[a[i]-'a']++;
        }
        for(int i=0;i<26;++i){
            if(cnt[i]>0) return cnt[i];
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>words_f;
        vector<int>ans;
        for(int i=0;i<words.size();++i){
            words_f.push_back(function(words[i]));
        }
        sort(words_f.begin(),words_f.end());
        for(int i=0;i<queries.size();++i){
            int queries_element=function(queries[i]);
            int left=0;
            int right=words_f.size()-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(words_f[mid]>queries_element){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            ans.push_back(words_f.size()-right-1);
        }
        return ans;
    }
};