class Solution {
public:
    vector<int>path;
    vector<vector<int>>result;
    void backtracking(vector<int>&candidates,int target,int sum,int startIndex,vector<bool>used ){
        if(sum==target){
            result.push_back(path);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false){
                continue;
            }
            path.push_back(candidates[i]);
            sum+=candidates[i];
            used[i]=true;
            backtracking(candidates,target,sum,i+1,used);
            used[i]=false;
            sum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0,used);
        return result;
    }
};