class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans{};
        if(nums.size()<4){
            return ans;
        }
        for(int i=0;i<=nums.size()-3;++i){
            if(nums[i]>target&&nums[i]>=0){
                break;
            }
            else if(i>0&&nums[i]==nums[i-1]){
                //去重
                continue;
            }
            for(int k=i+1;k<=nums.size()-2;++k){
                if((long long)nums[i]+nums[k]>target&&(long long)nums[i]+nums[k]>=0){
                    break;
                }
                else if(k>i+1&&nums[k]==nums[k-1]){
                    continue;
                }
                int left=k+1;
                int right=nums.size()-1;
                long long x=(long long )target-nums[i]-nums[k];
                while(left<right){
                    if((long long)nums[left]+nums[right]>x){
                        right--;
                    }
                    else if((long long)nums[left]+nums[right]<x){
                        left++;
                    }
                    else{
                        ans.push_back({nums[i],nums[k],nums[left],nums[right]});
                        while(left<right&&nums[right]==nums[right-1]){
                            right--;
                        }
                        while(left<right&&nums[left]==nums[left+1]){
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};