class Solution {
    int dirx[4] = { -1, 0, 0, 1 };
    int diry[4] = { 0, 1, -1, 0 };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row=maze.size();
        int col=maze[0].size();
        queue<pair<int,int>>que;
        que.push({entrance[0],entrance[1]});
        pair<int,int>begin{entrance[0],entrance[1]};
        int cnt=0;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;++i){
                pair<int,int>cur=que.front();
                que.pop();
                if((cur.first==0||cur.first==row-1||cur.second==col-1||cur.second==0)&&cur!=begin){
                    return cnt;
                }
                for(int i=0;i<4;i++){
                    int x=cur.first+dirx[i];
                    int y=cur.second+diry[i];
                    if(x>=0&&x<row&&y<col&&y>=0&&maze[x][y]=='.'){
                        maze[x][y]='+';
                        que.push({x,y});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};