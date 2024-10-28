class Solution {
public:
    void dfs(int node,vector<vector<int>>&isConnected,vector<bool>&visit){
        visit[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(visit[i]==false&&isConnected[node][i]==1){
                dfs(i,isConnected,visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visit(n,false);
        int province=0;
        for(int i=0;i<n;i++){
            if(visit[i]==false){
                province++;
                dfs(i,isConnected,visit);
            }
        }
        return province;
    }
};