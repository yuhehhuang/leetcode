class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(n+2,0);
        for(int i=0;i<n;++i){
            //f[i+2]map to index i的optimal solution
            f[i+2]=max(f[i+1],f[i]+nums[i]);
        }
        return f[nums.size()+1];
    }
};