class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>result;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])==map.end()){
                map[nums[i]]++;
                result.push_back(nums[i]);
            }
            else{
                if(map[nums[i]]>=2){
                    continue;
                }
                map[nums[i]]++;
                result.push_back(nums[i]);
            }
        }
        nums.clear();
        nums=result;
        return nums.size();
    }
};