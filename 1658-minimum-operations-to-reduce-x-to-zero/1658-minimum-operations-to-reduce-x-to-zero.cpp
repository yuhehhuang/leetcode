class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //變相成找最長的subarray sum=s-x;
        int left=0;
        int ans=INT_MIN;
        int tmp=0;
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        if (sum < 0) return -1; 
        for(int right=0;right<nums.size();++right){
            tmp+=nums[right];
            while(tmp>sum-x){
                tmp-=nums[left];
                left++;
            }
            if(tmp==sum-x){
                ans=max(ans,right-left+1);
            }
        }
        return ans==INT_MIN?-1:nums.size()-ans;
    }
};