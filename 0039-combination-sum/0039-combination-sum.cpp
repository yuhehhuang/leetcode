class Solution {
public:
    vector<int>path;
    vector<vector<int>>result;
    void backtracking(vector<int>& candidates,int target,int sum,int startIndex){
        if(sum==target){
            result.push_back(path);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum,i);
            sum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0,0);
        return result;
    }
};