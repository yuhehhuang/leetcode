class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        //難點是如何在連續k的array確保至少m個unique
        //建立一個map
        long long ans=0;
        long long max_ans=0;
        unordered_map<long long,int>mp;
        for(int i=0;i<k;++i){
            ans+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()>=m){
            max_ans=ans;
        }
        for(int i=k;i<nums.size();++i){
            ans+=nums[i]-nums[i-k];
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp.size()>=m){
                max_ans=max(max_ans,ans);
            }
        }
        return max_ans;
    }
};