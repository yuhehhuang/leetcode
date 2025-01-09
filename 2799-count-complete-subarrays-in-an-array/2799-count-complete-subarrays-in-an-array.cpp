class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        //枚舉right，找到第一個left [left,right]不滿足至少k個不同element
        int left=0;
        int ans=0;
        unordered_set<int>set;
        for(int num:nums){
            set.insert(num);
        }
        int k=set.size();
        unordered_map<int,int>mp;
        for(int right=0;right<nums.size();++right){
            mp[nums[right]]++;
            while(mp.size()==k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            ans+=left;
        }
        return ans;
    }
};