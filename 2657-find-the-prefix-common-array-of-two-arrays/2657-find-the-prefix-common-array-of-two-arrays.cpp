class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans(B.size(),0);
        unordered_map<int,int>mp;
        for(int i=0;i<A.size();++i){
            mp[A[i]]++;
            int tmp=0;
            for(int j=0;j<=i;++j){
                if(mp.find(B[j])!=mp.end()){
                    tmp++;
                }
            }
            ans[i]=tmp;
        }
        return ans;
    }
};