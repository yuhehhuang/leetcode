class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //恰好k個odd =>至少k個odd的case-至少k+1個odd的case
        auto f=[&](int k)->int{
            int left=0;
            int cnt=0;
            int ans=0;
            for(int right=0;right<nums.size();++right){
                if(nums[right]%2==1){
                    cnt++;
                }
                while(cnt>=k){
                    if(nums[left]%2==1){
                        cnt--;
                    }
                    left++;
                }
                ans+=left;
            }
            return ans;
        };
        return f(k)-f(k+1);
    }
};