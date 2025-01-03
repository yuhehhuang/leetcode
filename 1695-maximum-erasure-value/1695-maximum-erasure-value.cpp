class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>mp;
        int left=0;
        int ans=INT_MIN;
        int sum=0;
        for(int right=0;right<nums.size();++right){
            while(mp.find(nums[right])!=mp.end()){
                sum-=nums[left];
                mp.erase(nums[left]);
                left++;
            }
            mp.insert(nums[right]);
            sum+=nums[right];
            ans=max(ans,sum);
        }
        return ans;
    }
};