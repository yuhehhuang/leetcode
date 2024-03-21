class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right =nums.size()-1;
        while(left<=right){
            int n=(left+right)/2;
            if(nums[n]==target){
              return n;
            }
            else if(nums[n]>target){
                right=n-1;
            }
            else{
                left=n+1;
            }

        }
        return -1;
    }
};