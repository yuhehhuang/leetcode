class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total=accumulate(nums.begin(),nums.end(),0LL);
        int n=nums.size();
        int left=0;
        int ans=INT_MAX;
        long long sum=0;
        for(int right=0;right<2*n;++right){
            sum+=nums[right%n];
            while(sum>target%total){
                sum-=nums[left%n];
                left++;
            }
            if(sum==target%total){
                ans=min(ans,right-left+1);
            }
        }
        return ans==INT_MAX?-1:ans+target/total*n;
    }
};