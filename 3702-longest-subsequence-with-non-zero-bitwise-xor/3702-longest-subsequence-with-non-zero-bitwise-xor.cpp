class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int len=nums.size();
        int total=0;
        bool nonZero=false;
        for(int i=0;i<len;++i){
            if(nums[i]>0){
                nonZero=true;
            }
            total^=nums[i];
        }
        if(total!=0){
            return len;
        }
        if(nonZero){
            return len-1;
        }
        return 0;
    }
};