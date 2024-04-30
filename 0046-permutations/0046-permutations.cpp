class Solution {
public:
//偵測是自己的時候不要用
    vector<int>path;
    vector<vector<int>>result;
    void backtracking(vector<int>&nums,vector<bool> &used){
        if(path.size()==nums.size()){
            result.push_back(path);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,used);
            used[i]=false;
            path.pop_back();
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};