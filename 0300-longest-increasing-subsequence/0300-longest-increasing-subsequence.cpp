class Solution {
public:
    int dfs(vector<int>&nums,vector<int>&memo,int i){
        if(i<0){
            return 0;
        }
        int ans=0;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i]){
                if(memo[j]!=-1){
                    ans= max(memo[j],ans);
                }
                else{
                    ans=max(ans,dfs(nums,memo,j));
                }
            }
        }
        memo[i]=ans+1;
        return memo[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        int ans=0;
        for(int i=0;i<nums.size();++i){
            ans=max(ans,dfs(nums,memo,i));
        }
        return ans;
    }
};