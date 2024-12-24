class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(),-1);
        long long tmp=0;
        if(nums.size()<2*k+1){
            return ans;
        }
        for(int i=0;i<=2*k;++i){
            tmp+=nums[i];
        }
        ans[k]=tmp/(2*k+1);//i+k
        for(int i=k+1;i<nums.size();++i){
            if(i+k<nums.size()){
                tmp+=nums[i+k]-nums[i-k-1];
                ans[i]=tmp/(2*k+1);
            }
        }
        return ans;
    }
};