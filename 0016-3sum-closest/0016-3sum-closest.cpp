class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closet=INT_MAX;
        int ans=0;
        for(int i=0;i<=nums.size()-2;++i){
            int left=i+1;
            int right=nums.size()-1;
            //變成求最接近target-nums[i];
            while(left<right){
                if(closet>abs(target-(nums[left]+nums[right]+nums[i]))){
                    closet=abs(target-(nums[left]+nums[right]+nums[i]));
                    ans=nums[left]+nums[right]+nums[i];
                }
                if(nums[left]+nums[right]+nums[i]>target){
                    right--;
                }
                else if(nums[left]+nums[right]+nums[i]<target){
                    left++;
                }
                else{
                    return nums[left]+nums[right]+nums[i];
                }
            }
        }
        return ans;
    }
};