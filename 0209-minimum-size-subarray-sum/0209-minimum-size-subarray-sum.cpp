class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right=0;
        int ans=INT_MAX;
        int sum=0;
        int left=0;
        //for負責先增加windows，後續作while縮小window，目的是希望增加一個windows可以縮小>1個windows來更新答案
        for(right;right<nums.size();++right){
            sum+=nums[right];
            //while負責縮小windows
            while(sum-nums[left]>=target){
                sum-=nums[left++];
            }
            if(sum>=target){
                ans=min(ans,right-left+1);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};