class Solution {
public:
    void dfs(vector<vector<int>>&ans,vector<int>&path,int index,int& n,int&k){
        //終止條件
        if(path.size()==k){
            ans.push_back(path);
        }
        //
        for(int i=index;i<n+1;++i){
            if(n-index+1<k-path.size()){
                continue;
            }
            path.push_back(i);
            dfs(ans,path,i+1,n,k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(ans,path,1,n,k);
        return ans;

    }
};