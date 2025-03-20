class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int left=0;
        while(left<nums.size()-1){
            int right=left+1;
            while(nums[left]==0&&right<=nums.size()-1){
                nums[left]=nums[right];
                nums[right++]=0;
            }
            left++;
        }
        return nums;
    }
};