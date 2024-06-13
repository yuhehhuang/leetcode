class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    void dfs(vector<vector<int>>&graph,int x){
        if(x==graph.size()-1){
            result.push_back(path);
            return;
        }
        else{
            for(int i=0;i<graph[x].size();i++){
                path.push_back(graph[x][i]);
                dfs(graph,graph[x][i]);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph,0);
        return result;
    }
};