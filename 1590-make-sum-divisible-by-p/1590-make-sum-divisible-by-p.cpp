class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum=(totalSum+nums[i])%p;
        }
        int target=totalSum%p;
        if(target==0)return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int currentsum=0;
        int minLen=n;
        for(int i=0;i<n;i++){
            currentsum=(currentsum+nums[i])%p;
            int needed=(currentsum-target+p)%p;
            if(mp.find(needed)!=mp.end()){
                minLen=min(minLen,i-mp[needed]);
            }
            mp[currentsum]=i;
        }
        return minLen==n?-1:minLen;
    }
};