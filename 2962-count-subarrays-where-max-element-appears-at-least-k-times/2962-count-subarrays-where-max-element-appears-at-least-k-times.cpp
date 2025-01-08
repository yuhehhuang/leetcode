class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector<int> copy=nums;
        sort(copy.begin(),copy.end());
        int big=copy[copy.size()-1];
        int left=0;
        long long ans=0;
        int cnt=0;
        for(int right=0;right<nums.size();++right){
            if(nums[right]==big){
                cnt++;
            }
            while(cnt>=k){
                if(nums[left++]==big){
                    cnt--;
                }
            }
            ans+=left;
        }
        return ans;
    }
};