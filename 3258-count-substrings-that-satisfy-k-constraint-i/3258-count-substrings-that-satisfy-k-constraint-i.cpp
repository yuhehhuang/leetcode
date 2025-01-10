class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        //越小越合法
        int cnt[2]{};
        int left=0;
        int ans=0;
        for(int right=0;right<s.length();++right){
            cnt[s[right]-'0']++;
            //若不合法進入while
            while(cnt[0]>k&&cnt[1]>k){
                cnt[s[left++]-'0']--;
            }
            //此時left是第一個合法的位置
            //所以右壁=right時有right-left+1個可能
            ans+=right-left+1;
        }
        return ans;
    }
};