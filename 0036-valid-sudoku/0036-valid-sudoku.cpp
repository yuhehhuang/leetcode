class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check each row has not duplicate
        for(int row=0;row<board.size();++row){
            vector<int>check_row(10,0);
            for(int col=0;col<board[0].size();++col){
                if(board[row][col]=='.') continue;
                if(check_row[board[row][col]-'0']==0){
                    check_row[board[row][col]-'0']=1;
                }
                else{
                    return false;
                }
            }
        }
        //check each column has not duplicate
        for(int col=0;col<board[0].size();++col){
            vector<int>check_col(10,0);
            for(int row=0;row<board.size();row++){
                if(board[row][col]=='.') continue;
                if(check_col[board[row][col]-'0']==0){
                    check_col[board[row][col]-'0']=1;
                }
                else{
                    return false;
                }
            }
        }
        //check each 3x3 sub-boxes not duplicate
        //分三次大row(0~2,3~5，6~8) ，大row再切3個sub-boxes; 
        for(int k=0;k<3;++k){
            for(int i=0;i<3;++i){
                //此時已確定一個3x3的box
                vector<int>check_box(10,0);
                for(int row=0+3*k;row<3+3*k;++row){
                    for(int col=0+3*i;col<3+3*i;++col){
                        if(board[row][col]=='.') continue;
                        if(check_box[board[row][col]-'0']==0){
                            check_box[board[row][col]-'0']=1;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};