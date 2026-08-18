class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //row i 跑到 column (n-1-i)
        // col j rotate 90 to row j 
        //(i,j) --> (j,n-1-i);
        //(i,j) ->(j,i)->(j,n-1-i);
        //   transpose then reverse row!
        for(int row=0;row<matrix.size();++row){
            for(int col=0;col<row;++col){
                swap(matrix[row][col],matrix[col][row]);
            }
        }
        for(int row=0;row<matrix.size();++row){
            reverse(matrix[row].begin(),matrix[row].end());
        }
        return ;
    }
};