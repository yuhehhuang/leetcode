class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>ans;
        auto dfs=[&](auto&& self,int i)->void{
            ans.push_back(path);
            for(int j=i;j<nums.size();++j){
                path.push_back(nums[j]);
                self(self,j+1);
                path.pop_back();
            }
        };
        dfs(dfs,0);
        return ans;
    }
};