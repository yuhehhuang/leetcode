class Solution {
public:
    int find_min(vector<int>&nums){
        int left=0;
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
        return right+1;
    }
    int find_target(vector<int>&nums,int left,int right,int target){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return nums[left]==target?left:-1;
    }
    int search(vector<int>& nums, int target) {
        int index=find_min(nums);
        if(target>nums[nums.size()-1]){
            //一定是在波段型，且target在第一段上升段
            return find_target(nums,0,index-1,target);
        }
        else{
            if(index==0){
                //單一直線線段
                return find_target(nums,0,nums.size()-1,target);
            }
            else{
                //一定是在波段型，且target在第二段上升段
                return find_target(nums,index,nums.size()-1,target);
            }
        }
    }
};