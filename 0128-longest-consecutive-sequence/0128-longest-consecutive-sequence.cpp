class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        for(unordered_set<int>::iterator it=st.begin();it!=st.end();++it){
            int x=*it;
            if(st.find(x-1)!=st.end()){
                continue;
            }
            int y=x+1;
            while(st.find(y)!=st.end()){
                y++;
            }
            ans=max(ans,y-x);
        }
        return ans;
    }
};