class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0;
        int ans=INT_MIN;
        int k=1;
        //可能的subarray只有兩種可能 一種是全是1的第二種是只有一個0
        //題目變成求至多只能一個0的最長子陣列
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