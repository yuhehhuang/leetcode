class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),0));
        int ans=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==nums2[0]){
                dp[i][0]=1;
                ans=1;
            }
        }
        for(int j=0;j<nums2.size();j++){
            if(nums2[j]==nums1[0]){
                dp[0][j]=1;
                ans=1;
            }
        }
        for(int i=1;i<nums1.size();i++){
            for(int j=1;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }            
        }
        }
        return ans==INT_MIN?0:ans;
    }
};