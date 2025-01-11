class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        multiset<int>set;
        int left=0;
        for(int right=0;right<nums.size();++right){
            set.insert(nums[right]);
            while(*set.rbegin()-*set.begin()>2){
                set.erase(set.find(nums[left++]));
            }
            ans+=right-left+1;
        }
        return ans;
    }
};