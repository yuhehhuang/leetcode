class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        vector<int>result(nums1.size(),-1);
        st.push(0);
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=i;
        }
        for(int j=1;j<nums2.size();j++){
            if(nums2[j]<=nums2[st.top()]){
                st.push(j);
            }
            else{
                while(!st.empty()&&nums2[j]>nums2[st.top()]){
                    if(mp.find(nums2[st.top()])!=NULL){
                        result[mp[nums2[st.top()]]]=nums2[j];
                    }
                    st.pop();
                }
                st.push(j);
            }
        }
        return result;
    }
};