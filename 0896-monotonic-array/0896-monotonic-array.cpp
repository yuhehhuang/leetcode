class Solution {
public:
    bool isMonoIncrease(vector<int>&nums){
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i+1]-nums[i]<0){
                return false;
            }
        }
        return true;
    }
    bool isMonoDecrease(vector<int>&nums){
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i+1]-nums[i]>0){
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        return isMonoIncrease(nums)||isMonoDecrease(nums);
    }
};