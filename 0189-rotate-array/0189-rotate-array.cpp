class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>tmp;
        int start=nums.size()-k%nums.size();
        for(int i=start;i<start+nums.size();i++){
            tmp.push_back(nums[i%nums.size()]);
        }
        nums=tmp;
        return;
    }
};