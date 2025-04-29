class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<queries.size();++i){
            int cnt=0;
            for(int j=0;j<nums.size();++j){
                cnt+=nums[j];
                if(cnt>queries[i]){
                    ans.push_back(j);
                    break;
                }
                else if(j==nums.size()-1){
                    ans.push_back(j+1);
                    break;
                }
            }
        }
        return ans;
    }
};