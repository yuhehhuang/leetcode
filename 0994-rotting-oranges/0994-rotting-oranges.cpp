class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited=grid;
        queue<pair<int,int>>que;
        int cntFreshOrange=0;
        //把壞掉的橘子放進隊列，好橘子有幾個記起來
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==2){
                    que.push({i,j});
                }
                if(visited[i][j]==1){
                    cntFreshOrange++;
                }
            }
        }
        //
        if(cntFreshOrange==0){
            return 0;
        }
        int minute=-1;
        vector<int>dir_row={0,1,0,-1};
        vector<int>dir_col={1,0,-1,0};
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                pair<int,int>node=que.front();
                que.pop();
                for(int i=0;i<4;i++){
                    int next_row=node.first+dir_row[i];
                    int next_col=node.second+dir_col[i];
                    if(next_row>=0&&next_row<m&&next_col>=0&&next_col<n&&visited[next_row][next_col]==1){
                        visited[next_row][next_col]=2;
                        cntFreshOrange--;
                        que.push({next_row,next_col});
                    }
                }
            }
            minute++;
        }
        if(cntFreshOrange==0){
            return minute;
        }
        return -1;
    }
};