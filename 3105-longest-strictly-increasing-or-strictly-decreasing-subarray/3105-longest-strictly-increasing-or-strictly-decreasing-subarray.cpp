class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0;
        int cnt_plus=0;
        int cnt_minus=0;
        for(int i=0;i<nums.size();++i){
            cnt_plus++;
            if(i==nums.size()-1||nums[i]<=nums[i+1]){
                ans=max(ans,cnt_plus);
                cnt_plus=0;
            }
        }
        for(int i=0;i<nums.size();++i){
            cnt_minus++;
            if(i==nums.size()-1||nums[i]>=nums[i+1]){
                ans=max(ans,cnt_minus);
                cnt_minus=0;
            }
        }
        return ans;
    }
};