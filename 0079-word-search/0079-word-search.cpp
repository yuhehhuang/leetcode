class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool ans=false;
    void search(int row,int col,int index,vector<vector<char>>&board,string word){
        if(index==word.length()){
            ans=true;
            return;
        }
        if(row<0||row>=board.size()||col<0||col>=board[0].size()){
            return;
        }
        if(ans){
            return;
        }
        if(word[index]==board[row][col]){
            board[row][col]='.';
            for(int i=0;i<4;++i){
                search(row+dir[i].first,col+dir[i].second,index+1,board,word);
            }
            board[row][col]=word[index];
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=word.length();
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                search(i,j,0,board,word);
                if(ans==true)return true;
            }
        }
        return false;
    }
};