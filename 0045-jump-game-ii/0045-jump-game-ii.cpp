class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_can_jump=0;
        int next_can_jump=0;
        int result=0;
        if(nums.size()==1){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            next_can_jump=max(next_can_jump,nums[i]+i);
            if(i==cur_can_jump){
                if(i!=nums.size()){
                    result++;
                    cur_can_jump=next_can_jump;
                    if(cur_can_jump>=nums.size()-1){
                        break;
                    }
                }
            }
        }
        return result;
    }
};