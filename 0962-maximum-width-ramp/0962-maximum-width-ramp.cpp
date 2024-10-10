class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        //遍歷產生遞減stack
        //stack有i表示index:nums[i]是nums[0]~nums[i]中最小的 所以在stack內的元素不可能當右壁(因為左邊的都比他小)
        //所以遍歷後所以左壁可能都包含在stack了 
        stack<int>st;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(st.empty()||nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=nums[st.top()]){
                ans=max(ans,i-st.top());
                st.pop();
            }
        }
        return ans;
    }
};
