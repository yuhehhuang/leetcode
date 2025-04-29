class Solution {
public:
    int maximumCount(vector<int>& nums) {
        //最接近零但比0大的位置&找最接近零但比0小的位置
        int left=0;
        int right=nums.size()-1;
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<=0){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        //出來的left是最接近零但比0大的index
        ans=nums.size()-left;
        ////
        left=0;
        right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>=0){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        ans=max(ans,right+1);
        return ans;
    }
};