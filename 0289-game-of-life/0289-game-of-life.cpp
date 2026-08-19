class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //上下左右對角線
        //live cell 1:
        // neighbor<2 die
        //neighbor =2 or 3 live
        //neighbor>3 die
        //die cell 0:
        // neighbor 有3個live thenlive
        int m=board.size(),n=board[0].size();
        vector<vector<int>>tmp(m,vector<int>(n,0));
        //上下左右，左上，右上，右下，左下
        vector<pair<int,int>>check={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==1){
                    int die_cell=0;
                    int live_cell=0;
                    for(int k=0;k<8;++k){//不越界
                        if((i+check[k].first>-1&&i+check[k].first<m)&&(j+check[k].second>-1&&j+check[k].second<n)){
                            if(board[i+check[k].first][j+check[k].second]==0){
                                die_cell++;
                            }
                            else{
                                live_cell++;
                            }
                        }
                    }
                    if(live_cell==2 ||live_cell==3){
                        tmp[i][j]=1;
                    }
                    else{
                        tmp[i][j]=0;
                    }
                }
                else{
                    int live_cell=0;
                    for(int k=0;k<8;++k){//不越界
                        if((i+check[k].first>-1&&i+check[k].first<m)&&(j+check[k].second>-1&&j+check[k].second<n)){
                            if(board[i+check[k].first][j+check[k].second]==1){
                                live_cell++;
                            }
                        }
                    }
                    if(live_cell==3){
                        tmp[i][j]=1;
                    }
                    else{
                        tmp[i][j]=0;
                    }
                }
            }
        }
        board=tmp;
        return;
    }
};