vector<pair<int,int>>dim={{0,1},{0,-1},{-1,0},{1,0}};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        queue<pair<int,int>>que;
        que.push(pair<int,int>(sr,sc));
        int ini_color=image[sr][sc];
        image[sr][sc]=color;
        while(!que.empty()){
            pair<int,int>tmp=que.front();
            que.pop();
            for(int i=0;i<4;++i){
                if((tmp.first+dim[i].first)>=0&&(tmp.first+dim[i].first)<=image.size()-1&&(tmp.second+dim[i].second)>=0&&(tmp.second+dim[i].second<=image[0].size()-1)&&image[tmp.first+dim[i].first][tmp.second+dim[i].second]==ini_color){
                    que.push(pair<int,int>((tmp.first+dim[i].first),(tmp.second+dim[i].second)));
                    image[tmp.first+dim[i].first][tmp.second+dim[i].second]=color;
                }
            }
        }
        return image;
    }
};