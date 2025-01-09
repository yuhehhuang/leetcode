class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        int left=0;
        unordered_map<int,int>cnt;
        int pair=0;
        for(int x:nums){
            pair+=cnt[x];
            cnt[x]++;
            while(pair>=k){
                pair-=cnt[nums[left]]-1;
                cnt[nums[left]]--;
                left++;
            }
            ans+=left;
        }
        return ans;
    }
};