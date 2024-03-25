class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k>nums.size()){
            k=nums.size();
        }
        for(int i=k;i>0;i--){
            for(int j=0;j<nums.size()-i;j++){
                if(nums[j]==nums[j+i]){
                    return true;
                }
            }
        }
        return false;
    }
};