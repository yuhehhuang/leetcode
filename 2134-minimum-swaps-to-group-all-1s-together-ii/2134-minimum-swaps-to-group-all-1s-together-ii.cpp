class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //先確認vector有幾個1，假設5個表示我最終要有5個連續的1，
        //用一個window長度5，遍例全部，當window內0的數最少的就是最佳解
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                cnt++;
            }
        }
        int swap=0;
        for(int i=0;i<cnt;++i){
            if(nums[i]==0){
                swap++;
            }
        }
        int ans=swap;
        for(int i=cnt;i<cnt+nums.size()-1;++i){
            if(nums[i%nums.size()]==0&&nums[(i-cnt)%nums.size()]==1){
                swap++;
            }
            if(nums[i%nums.size()]==1&&nums[(i-cnt)%nums.size()]==0){
                swap--;
            }
            ans=min(ans,swap);
        }
        return ans;
    }
};