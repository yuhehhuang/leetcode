class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        //偶奇偶奇
        //全部值<=threshold
        int i=0;
        int ans=0;
        while(i<nums.size()){
            int left=i;
            if(nums[left]%2==0&&nums[left]<=threshold){
                while(i<nums.size()-1&&nums[i]%2!=nums[i+1]%2){
                    if(nums[i+1]<=threshold){
                        i++;
                    }
                    //i停在最後一個合格成員
                    else{
                        break;
                    }
                }
            }
            ans=nums[left]%2==0&&nums[left]<=threshold?max(ans,i-left+1):max(ans,0);
            i++;
        }
        return ans;
    }
};