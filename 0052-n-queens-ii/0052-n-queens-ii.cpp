class Solution {
public:
    bool valid(int row,int col,vector<int>&column){
        for(int i=0;i<row;++i){
            if(column[i]==col||column[i]+i==row+col||column[i]-i==col-row){
                return false;
            }
        }
        return true;
    }
    void dfs(int& n,int& ans,vector<int>&column,int row){
        if(row==n){
            ans++;
            return;
        }
        for(int c=0;c<n;++c){
            if(valid(row,c,column)){
                column[row]=c;
                dfs(n,ans,column,row+1);
                //column[row]=-1;
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<int>column(n,-1);//紀錄queen在第i個row的第幾個col
        dfs(n,ans,column,0);
        return ans;      
    }
};