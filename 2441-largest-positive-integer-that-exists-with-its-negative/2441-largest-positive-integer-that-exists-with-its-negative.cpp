class Solution {
public:
    int findMaxK(vector<int>& nums) {
    unordered_map<int,int>map;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    for(int i=nums.size()-1;i>=0;i--){
        if(map.count((-1)*nums[i])){
            return nums[i];
        }
    }
    return -1;

}
};