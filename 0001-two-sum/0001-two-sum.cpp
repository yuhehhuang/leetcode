class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> book;
        for(int i=0;i<nums.size();i++){
             map<int,int>::iterator iter = book.find(target - nums[i]); 
            if(iter!=book.end()){
                return{iter->second,i};
            }
            else{
                 book.insert(pair<int, int>(nums[i], i)); 
            }
        }
        return {};
    }
};