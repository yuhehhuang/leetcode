class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
       int n=nums.size();
       vector<vector<int>>pos_list(n+1);
       for(int i=0;i<n;++i){
        int x=nums[i];
        pos_list[x].push_back(i);
       }
       int ans=0;
       for(int i=0;i<pos_list.size();++i){
        int left=0;
        for(int right=0;right<pos_list[i].size();++right){
            while(pos_list[i][left]-pos_list[i][right]-(right-left)>k){
                left++;
            }
            ans=max(ans,right-left+1);
        }
       }
        return ans;
    } 
};