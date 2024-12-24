class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=0;
        vector<int>memo(blocks.size());
        if(k>blocks.length()){
            return -1;
        }
        for(int i=0;i<k;++i){
            if(blocks[i]=='W'){
                ans++;
            }
        }
        int Min_oper=ans;
        for(int i=k;i<blocks.length();++i){
            if(blocks[i]=='W'){
                ans++;
            }
            if(blocks[i-k]=='W'){
                ans--;
            }
            Min_oper=min(Min_oper,ans);           
        }
        return Min_oper;
    }
};