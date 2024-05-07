class Solution {
public:
    int jump(vector<int>& nums) {
        int cur=0;
        int result=0;
        int next;
        for(int i=0;i<nums.size();i++){
            next=max(next,nums[i]+i);
            if(i==cur){
                if(cur!=nums.size()-1){
                    result++;
                    cur=next;
                    if(next>=nums.size()-1){
                        break;
                    }
                }
            }
        }
        return result;
    }
};