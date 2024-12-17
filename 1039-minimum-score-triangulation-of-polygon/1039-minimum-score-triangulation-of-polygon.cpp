class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        //dfs(i,j):從index i到index j的最佳解=min 某個k that:(v[i]*v[j]*v[k]+dfs(i,k)+dfs(k,j));
        int n=values.size();
        vector<vector<int>>f(n,vector<int>(n,0));
        for(int i=n-3;i>=0;--i){
            for(int j=i+2;j<n;++j){
                f[i][j]=INT_MAX;
                for(int k=i+1;k<j;++k){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]+values[i]*values[j]*values[k]);
                }
            }
        }
        return f[0][n-1];     
    }
};