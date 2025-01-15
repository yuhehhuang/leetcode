class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int right=nums.size()-1;
        for(int left=0;left<nums.size()-1;++left){
            while(left<right&&nums[left]+nums[right]>=target){
                right--;
            }
            ans+=left<right?right-left:0;
        }
        return ans;
    }
};