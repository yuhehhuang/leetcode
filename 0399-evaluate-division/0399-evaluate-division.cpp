class Solution {
public:
    vector<double>res;
    bool Nofand;
    void dfs(unordered_map<string,vector<pair<string,double>>>&g,unordered_map<string,int>&visit,string val,string& target, double path){
        if(Nofand==false) return;
        if(val==target){
            Nofand=false;
            res.push_back(path);
            return;
        }
        for(int j=0;j<g[val].size();++j){
            if(visit[g[val][j].first]==0){
                visit[g[val][j].first]=1;
                dfs(g,visit,g[val][j].first,target,path*g[val][j].second);
                visit[g[val][j].first]=0;
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>g;
        unordered_map<string,int>visit;
        //make undirected graph
        for(int i=0;i<equations.size();++i){
            g[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            g[equations[i][1]].push_back(make_pair(equations[i][0],1.0/values[i]));
        }
        //
        for(int i=0;i<queries.size();++i){
            if(g.find(queries[i][0])==g.end()){
                res.push_back(-1.0);
                continue;
            }
            Nofand=true;
            visit[queries[i][0]]=1;
            dfs(g,visit,queries[i][0],queries[i][1],1);
            visit[queries[i][0]]=0;
            if(Nofand)
            res.push_back(-1.0);
        }
        return res;
    }
};