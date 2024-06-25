class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window
        int window_len=0;
        int start=0;
        unordered_map<char,int>latest_index;//紀錄每個char最新一次出現在哪
        for(int end=0;end<s.size();end++){
            //lastest_index[s[end]]>=start表示最右邊這個重複的不會影響目前的window,可以不用管直接算長度(我們在意的是window內不要重複 window左邊有重複地沒關係!)
            if(latest_index.find(s[end])!=latest_index.end()&&latest_index[s[end]]>=start){
                start=latest_index[s[end]]+1;
            }
            latest_index[s[end]]=end;//更新最新一次出現在哪
            window_len=max(window_len,end-start+1);
        }
        return window_len;
    }
};
