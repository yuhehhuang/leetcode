class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0;
        int i0=-1,i1=-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>right){
                i0=i;
            }
            if(nums[i]>=left){
                i1=i;
            }
            ans+=i1-i0;
        }
        return ans;
    }
};