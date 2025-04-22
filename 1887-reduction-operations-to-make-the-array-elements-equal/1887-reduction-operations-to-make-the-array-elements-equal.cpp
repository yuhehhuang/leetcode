class Solution {
public:
    static bool cmp(int &a,int &b){
        return a>b;
    }
    int reductionOperations(vector<int>& nums) {
        //排序 遇到第一個不同大小的，表示要操作(b-a+1)次
        sort(nums.begin(),nums.end(),cmp);
        int i=0;
        int ans=0;
        while(i<nums.size()){
            while(i<nums.size()-1&&nums[i]==nums[i+1]){//出去時i在最後一個相同的位置
                i++;
            }
            //確認不是最後一組
            if(nums[i]!=nums[nums.size()-1]){
                ans+=i+1;
            }
            i++;
        }
        return ans;
    }
};