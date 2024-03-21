class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int maxLen=0;
        unordered_map<int, int> mp{{0, -1}}; //初始化key:0 value:-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==1?1:-1;
            if(mp.count(sum)){
                maxLen=max(maxLen,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return maxLen;
    }
};