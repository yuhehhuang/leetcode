class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans=0;
        int pre_cnt=0;
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            cnt++;
            if(i==nums.size()-1||nums[i]>=nums[i+1]){
                ans=max({ans,cnt/2,min(pre_cnt,cnt)});
                pre_cnt=cnt;
                cnt=0;
            }
        }
        return ans;
    }
};