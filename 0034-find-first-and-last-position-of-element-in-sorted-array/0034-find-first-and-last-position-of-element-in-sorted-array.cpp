class Solution {
public:
    int bs(vector<int>&nums,int target){
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right+1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //first position=第一個>=target的數
        //last position=第一個>=target+1的數的左邊
        if(nums.size()==0){
            return {-1,-1};
        }
        int first=bs(nums,target);
        if(first==nums.size()||nums[first]!=target){
            return {-1,-1};
        }
        int second=bs(nums,target+1)-1;
        return {first,second};
    }
};