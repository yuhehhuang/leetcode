class Solution {
public:
    static bool cmp(int a,int b){
        return a>b;
    }
    int lengthOfLIS(vector<int>& nums) {
        //dp
        vector<int>dp(nums.size(),1);//每個值至少有自己當作結果(len=1);
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        sort(dp.begin(),dp.end(),cmp);
        return dp[0];
    }
};