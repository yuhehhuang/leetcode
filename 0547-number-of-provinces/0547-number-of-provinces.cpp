class Solution {
public:
    void dfs(int node,vector<vector<int>>&isConnected,vector<bool>&visit){
        visit[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1&&visit[i]==false){
                dfs(i,isConnected,visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int province=0;
        vector<bool>visit(n);
        for(int i=0;i<n;i++){
            if(visit[i]==false){
                province++;
                dfs(i,isConnected,visit);
            }
        }
        return province;
    }
};