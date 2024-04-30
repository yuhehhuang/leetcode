class Solution {
public:
vector<int>path;
vector<vector<int>>result;
void backtracking(vector<int>&nums,vector<bool>&used){
    if(path.size()==nums.size()){
        result.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        //同一層去重判斷
        if(i>0&&used[i-1]==false&&nums[i]==nums[i-1]){
            continue;
        }
        //深度上不要選到自己 used[i]==false表示沒選到自己
        if(used[i]==false){
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            used[i]=false;
            path.pop_back();
        }
    }
    return ;

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};