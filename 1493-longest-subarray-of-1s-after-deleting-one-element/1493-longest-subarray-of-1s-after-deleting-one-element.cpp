class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0;
        int ans=INT_MIN;
        int k=1;
        while(right<nums.size()){
            if(nums[right]==0){
                k--;
            }
            while(k<0){
                if(nums[left]==0){
                    k++;
                    left++;
                }
                else{
                    left++;
                }
            }
            ans=max(ans,right-left);
            right++;
        }
        return ans;
    }
};