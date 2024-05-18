class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        if(obstacleGrid.size()==1&&obstacleGrid[0].size()==1){
            return obstacleGrid[0][0]==0?1:0;
        }
        dp[0][0]=obstacleGrid[0][0]==0?1:0;
     for(int i=1;i<obstacleGrid.size();i++){
        if(obstacleGrid[i][0]==0){
            dp[i][0]=1;
        }
        else{
            //column在石頭以下的都走不到--->都是預設0
            break;
        }
     }
     for(int j=1;j<obstacleGrid[0].size();j++){
        if(obstacleGrid[0][j]==0){
            dp[0][j]=1;
        }
        else{
            break;
        }
     }
     for(int j=1;j<obstacleGrid[0].size();j++){
        for(int i=1;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][j]==0){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            else{
                continue;
            }
        }
     }
     return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];  
    }
};