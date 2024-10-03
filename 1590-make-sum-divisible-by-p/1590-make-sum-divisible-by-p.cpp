class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum=(totalsum+nums[i])%p;
        }
        if(totalsum%p==0){
            return 0;
        }
        int currentsum=0;
        int target=totalsum%p;
        int minLen=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            currentsum=(currentsum+nums[i])%p;
            int needed=(currentsum-target+p)%p;
            if(mp.find(needed)!=mp.end()){
                minLen=min(minLen,i-mp[needed]);
            }
            mp[currentsum]=i;
        }
        return minLen==nums.size()?-1:minLen;

    }
};