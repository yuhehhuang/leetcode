class Solution {
public:
    void backtracking(vector<int>&nums,int index,int currentOR,int maxOR,int &cnt){
        if(currentOR==maxOR){
            cnt++;
        }
        for(int i=index;i<nums.size();++i){
            int prevOR=currentOR;
            currentOR|=nums[i];
            backtracking(nums,i+1,currentOR,maxOR,cnt);
            currentOR=prevOR;
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR=0;
        for(int i=0;i<nums.size();i++){
            maxOR|=nums[i];
        }
        int cnt=0;
        backtracking(nums,0,0,maxOR,cnt);
        return cnt;
    }
};