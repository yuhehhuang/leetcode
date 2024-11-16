class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;++i){
            int x=nums[i];
            int left=i+1;
            int right=nums.size()-1;
            if(i>0&&nums[i]==nums[i-1]){//i去重
                continue;
            }
            if(x+nums[left]+nums[left+1]>0){
                break;
            }
            if(x+nums[nums.size()-1]+nums[nums.size()-2]<0){
                continue;
            }
            while(left<right){
                int sum=x+nums[left]+nums[right];
                if(sum<0){
                    left++;
                }
                else if(sum>0){
                    right--;
                }
                else{//j,k去重
                    ans.push_back(vector<int>{x,nums[left],nums[right]});
                    left++;
                    while(left<right&&nums[left]==nums[left-1]){
                        left++;
                    }
                    right--;
                    while(left<right&&nums[right]==nums[right+1]){
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};