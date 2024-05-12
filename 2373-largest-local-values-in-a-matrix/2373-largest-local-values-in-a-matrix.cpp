class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int size=grid.size();
        vector<vector<int>>ans(size-2,vector<int>(size-2,0));
        for(int k=0;k<=size-3;k++){
            for(int i=0;i<=size-3;i++){
                int max=INT_MIN;
                for(int p=k;p<=k+2;p++){
                    for(int j=i;j<=i+2;j++){
                        if(max<grid[p][j]){
                            max=grid[p][j];
                        }
                    }
                }
                ans[k][i]=max;
            }
        }
        return ans;
    }
};