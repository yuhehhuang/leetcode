class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int ans=0;
        int left=0;
        int right=0;
        while(right<s.size()){
            while(st.find(s[right])!=st.end()){
                //case :找到重複元素 把它位置找到並刪除
                st.erase(s[left++]);
            }
            st.insert(s[right]);
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};