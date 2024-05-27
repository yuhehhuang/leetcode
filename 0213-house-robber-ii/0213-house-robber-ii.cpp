class Solution {
public:
    int robRange(vector<int> nums,int start,int end){
        if (end == start) return nums[start];
        vector<int>dp(nums.size(),0);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        //最佳解在index:0~n-2或1~n-1兩種範圍內
        if(nums.size()==1){
            return nums[0];
        }
        int result1=robRange(nums,0,nums.size()-2);
        int result2=robRange(nums,1,nums.size()-1);
        return max(result1,result2);
    }
};