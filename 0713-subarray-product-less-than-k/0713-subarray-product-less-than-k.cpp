class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //nums[i]>0
        //固定每個右壁，找最長的left使[left,right]<k則有right-left+1個可以連續相乘<k的結果
        if(k<=1){
            return 0;
        }
        int ans=0;
        int prod=1;
        int left=0;
        for(int right=0;right<nums.size();++right){
            prod*=nums[right];
            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
};