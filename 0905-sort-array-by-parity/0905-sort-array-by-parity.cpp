class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int tmp=0;
        //right右邊都是確定odd number,left左邊都是確定even number
        while(left<=right){
            if(nums[left]%2==1){
                tmp=nums[right];
                nums[right]=nums[left];
                nums[left]=tmp;
                right--;
            }
            else{
                left++;
            }
        }
        return nums;
    }
};