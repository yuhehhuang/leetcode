class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,cnt=k;
        int ans=0;
        while(right<nums.size()){
            if(nums[right]==0){
                cnt--;
            }
            while(cnt<0){
                if(nums[left]==0){
                    cnt++;
                }
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};