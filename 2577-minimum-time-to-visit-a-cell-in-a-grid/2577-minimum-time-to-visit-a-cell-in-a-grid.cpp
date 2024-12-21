class Solution {
    static constexpr int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][1]>1&&grid[1][0]>1){
            return -1;
        }
        int dis[m][n];
        memset(dis,0x3f,sizeof(dis));
        dis[0][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq; //min_heap
        pq.emplace(0,0,0);
        while(1){
            auto[d,i,j]=pq.top();
            pq.pop();
            if(i==m-1&&j==n-1){
                return d;
            }
            for(int k=0;k<4;++k){
                int x=i+dirs[k][0];
                int y=j+dirs[k][1];
                if(0<=x&&x<m&&0<=y&&y<n){
                    int nd=max(d+1,grid[x][y]);
                    nd+=(nd-x-y)%2;// nd=gird[x][y]時，grid[x][y]可能是不同奇偶性，要修正
                    if(nd<dis[x][y]){
                        dis[x][y]=nd;
                        pq.emplace(nd,x,y);
                    }              
                }
            }
        }
    }
};