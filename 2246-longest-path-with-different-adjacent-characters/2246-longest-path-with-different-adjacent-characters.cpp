class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>g(n);
        //建樹
        for(int i=1;i<n;++i){
            g[parent[i]].push_back(i);
        }
        //
        int ans=0;
        auto dfs=[&](auto&& dfs,int x)->int{
            int maxLen=0;
            for(int i=0;i<g[x].size();++i){
                int len=dfs(dfs,g[x][i])+1;
                if(s[g[x][i]]!=s[x]){
                    ans=max(ans,maxLen+len);
                    maxLen=max(maxLen,len);
                }
            }
            return maxLen;
        };
        dfs(dfs,0);
        return ans+1;
    }
};