class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int compare=-1;
        for(auto i:mp){
            if(i.second>compare){
                compare=i.second;
            }
        }
        for(auto i:mp){
            if(i.second==compare){
                sum+=compare;
            }
        }
        return sum;
    }
};