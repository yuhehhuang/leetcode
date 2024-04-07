class Solution {
public:
    int signFunc(int product){
        if(product>0){
            return 1;
        }
        if(product==0){
            return 0;
        }
        return -1;
    }
    int arraySign(vector<int>& nums) {
        int product=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                nums[i]=1;
            }
            if(nums[i]==0){
                return 0;
            }
            if(nums[i]<0){
                nums[i]=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
        }
        return signFunc(product);
    }
};