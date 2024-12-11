class Solution {
public:
    int dfs(vector<int>&nums,int index,vector<int>&memory){
        if(index<0){
            return 0;
        }
        if(memory[index]!=-1){
            return memory[index];
        }
        int res=max(dfs(nums,index-1,memory),dfs(nums,index-2,memory)+nums[index]);
        memory[index]=res;
        return res;
    }
    int rob(vector<int>& nums) {
        vector<int> memory(nums.size(),-1);
        return dfs(nums,nums.size()-1,memory);
    }
};