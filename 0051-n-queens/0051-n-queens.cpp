class Solution {
public:
    vector<vector<string>>result;
    void backtracking(int n,int row,vector<string>&chessboard){
        if(row==n){
            result.push_back(chessboard);
            return;
        }
        for(int col=0;col<n;col++){
            if(valid(row,col,chessboard,n)){
                chessboard[row][col]='Q';
                backtracking(n,row+1,chessboard);
                chessboard[row][col]='.';
            }
        } 
    }
    //因為一開始同個row都是'.'，所以同個row不用判斷有可能有重複queen
    //檢查點上方不能有queen,左對角線不能有queen,右對角線不能有queen
    bool valid(int row,int col,vector<string>&chessboard,int n){
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>chessboard(n,string(n,'.'));
        backtracking(n,0,chessboard);
        return result;
    }
};