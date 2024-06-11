class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        st.push(0);
        vector<int>result(nums.size(),-1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty()&&nums[i]>nums[st.top()]){
                    result[st.top()]=nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        for(int j=0;j<nums.size()-1;j++){
            if(nums[j]<=nums[st.top()]){
                continue;
            }
            else{
                while(!st.empty()&&nums[j]>nums[st.top()]){
                    result[st.top()]=nums[j];
                    st.pop();
                }
            }
        }
        return result;
    }
};