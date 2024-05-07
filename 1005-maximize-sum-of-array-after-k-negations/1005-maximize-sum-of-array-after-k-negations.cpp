class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    int result=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0&&k>0){
                nums[i]=-1*nums[i];
                k--;
            }
        }
        sort(nums.begin(),nums.end());
        if(k%2==1&&k>0){
            nums[0]=-1*nums[0];
            k--;
        }
        for(int i=0;i<nums.size();i++){
            result+=nums[i];
        }
        return result;
    }
};