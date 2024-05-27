class Solution {
public:
    int specialArray(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int i=0;i<=nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]>=i){
                    map[i]++;
                }
            }
        }
        for(int i=0;i<=nums.size();i++){
            if(i==map[i]){
                return i;
            }
        }
        return -1;
    }
};