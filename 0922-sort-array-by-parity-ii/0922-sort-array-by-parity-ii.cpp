class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        //只處理偶數
        int left=0;
        int right=nums.size()-1;
        int tmp;
        while(left<=nums.size()-1){
            if(nums[left]%2==1&&left%2==0){
                int tmp=nums[left];
                nums[left]=nums[right];
                nums[right]=tmp;
                right-=2;
            }
            else{
                left++;
            }
        }
        return nums;
    }
};