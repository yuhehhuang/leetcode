class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int compare=-1;
        for(unordered_map<int,int>::iterator it=mp.begin();it!=NULL;it++){
            if(it->second>compare){
                compare=it->second;
            }
        }
        for(unordered_map<int,int>::iterator it=mp.begin();it!=NULL;it++){
            if(it->second==compare){
                sum+=compare;
            }
        }
        return sum;
    }
};
