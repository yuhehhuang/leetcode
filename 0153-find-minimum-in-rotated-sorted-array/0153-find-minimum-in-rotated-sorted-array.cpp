class Solution {
public:
    int findMin(vector<int>& nums) {
        //紅:最小值左側，藍:最小值或最小值右側
        int left=0;
        //因為最小值在數組中，所以最右邊的值一定是最小值或最小值右側
        int right=nums.size()-2;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[nums.size()-1]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return nums[right+1];
    }
};