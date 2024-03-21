class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowindex=0;
        for(int fastindex=0;fastindex!=nums.size();fastindex++){
            if(nums[fastindex]!=val){
                nums[slowindex++]=nums[fastindex];
            }
        }
        return slowindex;
    }
};