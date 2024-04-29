class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    void backtracking(vector<int>& nums,int startIndex){
        if(path.size()>1){
            result.push_back(path);
        }
        unordered_set<int> uset;
        for(int i=startIndex;i<nums.size();i++){
            if(!path.empty()&&path.back()>nums[i]||uset.find(nums[i])!=NULL){
                continue;
            }
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
        return ;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
};