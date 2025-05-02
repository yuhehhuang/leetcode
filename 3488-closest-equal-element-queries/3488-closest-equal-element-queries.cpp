class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<nums.size();++i){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<queries.size();++i){
            int index=queries[i];
            int target=nums[index];
            int min_dist=INT_MAX;
            for(int pos:mp[target]){
                if(pos!=index){
                    int dist=abs(pos-index);
                    dist=min(dist,n-dist);
                    min_dist=min(min_dist,dist);
                }
            }
            ans.push_back(min_dist==INT_MAX?-1:min_dist);
        }
        return ans;
    }
};