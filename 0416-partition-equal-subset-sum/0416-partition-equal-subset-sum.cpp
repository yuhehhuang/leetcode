bool dfs(vector<int>& nums,int i,int j,vector<vector<int>>&memo){
    if(i<0){
        return j==0;
    }
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    if(j<nums[i]){
        return memo[i][j]=dfs(nums,i-1,j,memo);
    }
    return memo[i][j]=dfs(nums,i-1,j-nums[i],memo)||dfs(nums,i-1,j,memo);
}
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2==1){
            return false;
        }
        int n=nums.size();
        vector<vector<int>> memo(n, vector<int>(sum/2 + 1, -1)); //memo[i][j]=False; for all;
        return dfs(nums,n-1,sum/2,memo);
    }
};