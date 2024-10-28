class Solution {
public:
    int ans=0;
    void dfs(int current,int parent,vector<vector<int>>&tree){
        for(int i=0;i<tree[current].size();++i){
            int neighbor=tree[current][i];
            int city=abs(neighbor);
            if(city!=parent){ //tree[current]能到的只有current兒子以及current爸爸,要把爸爸排除(因為從爸爸遞歸來的)
                if(neighbor>0)ans++;
                dfs(city,current,tree);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>tree(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            tree[u].push_back(v); //u->v
            tree[v].push_back(-u);
        }
        dfs(0,-1,tree);
        return ans;
    }

};