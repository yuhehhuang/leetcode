class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;
    void backtracking(int k,int n,int startIndex,int sum){
        if(path.size()==k){
            if(sum==n){
                ans.push_back(path);
            }
            return ;
        }
        for(int i=startIndex;i<=9;i++){
            sum+=i;
            path.push_back(i);
            backtracking(k,n,i+1,sum);
            sum-=i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1,0);
        return ans;
    }
};