class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(vector<int>&nums,int target,int sum,int startIndex){
       if(sum==target){
        result.push_back(path);
       }
       for(int i=startIndex;i<nums.size()&&nums[i]+sum<=target;i++){
        sum+=nums[i];
        path.push_back(nums[i]);
        backtracking(nums,target,sum,i+1);
        sum-=nums[i];
        path.pop_back();
       } 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(target>sum){
            return 0;
        }
        if((sum+target)%2){
            return 0;
        }
        int bag=(sum+target)/2;
        sort(nums.begin(),nums.end());
        result.clear();
        path.clear();
        backtracking(nums,bag,0,0);
        return result.size();
    }
};