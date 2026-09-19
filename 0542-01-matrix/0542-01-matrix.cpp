class Solution {
public:
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>&ans,vector<vector<int>>&mat){
        queue<pair<int,int>>que;
        for(int i=0;i<mat.size();++i){
            for(int j=0;j<mat[0].size();++j){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    que.push(pair<int,int>(i,j));
                }
            }
        }
        while(!que.empty()){
            pair<int,int>x = que.front();
            que.pop();
            for(int k=0;k<=3;++k){
                int next_i=x.first+dir[k].first;
                int next_j=x.second+dir[k].second;
                if(next_i>=0&&next_i<mat.size()&&next_j>=0&&next_j<mat[0].size()&&ans[next_i][next_j]==-1){
                    ans[next_i][next_j]=ans[x.first][x.second]+1;
                    que.push(pair<int,int>(next_i,next_j));
                }
            }
        }
        return ;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
         bfs(ans,mat);
        return ans;
    }
};