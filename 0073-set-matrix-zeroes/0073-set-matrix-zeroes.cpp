class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //我們把需要設定全部都設為0的row&col的第一個設為0
        //避免matrix[0][0]代表row跟col都清0，
        //matrix[0][0]代表row0清0。
        bool col0 = false;
        
        for(int i=0;i<matrix.size();++i){
            if(matrix[i][0]==0){
                col0=true;
            }
            for(int j=1;j<matrix[0].size();++j){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();++i){
            for(int j=1;j<matrix[0].size();++j){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        //處理row 0
        if(matrix[0][0]==0){
            for(int i=0;i<matrix[0].size();++i){
                matrix[0][i]=0;
            }
        }
        if(col0){
            for(int i=0;i<matrix.size();++i){
                matrix[i][0]=0;
            }
        }
        return ;
    }
};