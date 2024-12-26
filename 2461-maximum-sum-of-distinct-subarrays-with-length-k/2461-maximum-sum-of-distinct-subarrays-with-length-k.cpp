class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long  ans=0;
        long long max_ans=0;
        for(int i=0;i<k;++i){
            ans+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k){
            max_ans=ans;
        }
        for(int i=k;i<nums.size();++i){
            ans+=nums[i]-nums[i-k];
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            if(mp.size()==k){
                max_ans=max(max_ans,ans);
            }
        }
        return max_ans;
    }
};