class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();++i){
            pair<int,int>node={nums[i],i};
            vec.push_back(node);
        }
        sort(vec.begin(),vec.end());
        return vec[nums.size()-1].second;

    }
};