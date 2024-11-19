class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int left=0;
        int right=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[n]&&target>nums[n]&&nums[mid]>=target){
                right=mid-1;
            }
            else if(nums[mid]<=nums[n]&&target>nums[n]){
                right=mid-1;
            }
            else if(nums[mid]<=nums[n]&&nums[mid]>=target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return nums[left]==target?left:-1;
    }
};