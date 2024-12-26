class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long  sum=0;
        long long max_ans=0;
        int dist=0;
        int vis[100001]={0};
        for(int i=0;i<k;++i){
            sum+=nums[i];
            vis[nums[i]]++;
            if(vis[nums[i]]==1){
                dist++;
            }
        }
        if(dist==k){
            max_ans=sum;
        }
        for(int i=k;i<nums.size();++i){
            vis[nums[i]]++;
            if(vis[nums[i]]==1){
                dist++;
            }//他跟上一輪的元素都不重複
            vis[nums[i-k]]--;
            if(vis[nums[i-k]]==0){
                dist--;
            }
            sum+=nums[i]-nums[i-k];
            if(dist==k){
                max_ans=max(max_ans,sum);
            }
        }
        return max_ans;
    }
};