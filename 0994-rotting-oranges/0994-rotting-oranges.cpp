class Solution {
    int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //建立一個quueue，放rotten orange座標(且是還沒往外汙染新鮮orange);
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>que;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    que.push({i,j});
                }
            }
        }
        while(fresh && !que.empty()){
            ans++;
            int len=que.size();
            for(int x=0;x<len;++x){
                pair<int,int>tmp=que.front();
                que.pop();
                for(int i=0;i<4;++i){
                    int index_x=tmp.first+directions[i][0],index_y=tmp.second+directions[i][1];
                    if(index_x>=0&&index_x<m&&0<=index_y&&index_y<n&&grid[index_x][index_y]==1){
                        fresh--;
                        grid[index_x][index_y]=2;
                        que.push({index_x,index_y});
                    }
                }
            }
        }
        return fresh?-1:ans;
    }
};