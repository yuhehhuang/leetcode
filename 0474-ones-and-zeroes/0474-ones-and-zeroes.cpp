class Solution {
    using pii=pair<int,int>;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<pii>count(sz,pair<int,int>(0,0));
        for(int i=0;i<sz;i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0'){
                    count[i].first++;
                }
                if(strs[i][j]=='1'){
                    count[i].second++;
                }
            }
        }
        vector<vector<vector<int>>> dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        int k1_inti=count[0].first,k2_inti=count[0].second;
        //dp[i][j][l]:代表從index第0到i的物品中 背包大小:(0可有j個 1可有l個)，這樣的背包能裝的最大元素個數量
        //case 物件0處理(dp初始化) 當背包大小購放物件0 都設1;
        for(int j=0;j<m+1;j++){
            for(int l=0;l<n+1;l++){
                //若背包大小夠買第0個物品 肯定買(才能最大值) 
                if(k1_inti<=j&&k2_inti<=l){
                    dp[0][j][l]=1;
                }
            }
        }
        for(int i=1;i<sz;i++){// 第0到第i個物品選
            int k1=count[i].first,k2=count[i].second;
            for(int j=0;j<m+1;j++){ //背包"0"的大小
                for(int l=0;l<n+1;l++){ //背包"1"的大小
                    if(k1<=j&&k2<=l){
                        //背包大小可以買第i個物品: max(買,不買)
                        dp[i][j][l]=max(dp[i-1][j-k1][l-k2]+1,dp[i-1][j][l]);
                    }
                    //背包大小無法買東西，-->跟0到i-1個物品的最佳解一樣
                    else dp[i][j][l]=dp[i-1][j][l];
                }
            }
        }
        return dp[sz-1][m][n];
    }
};
