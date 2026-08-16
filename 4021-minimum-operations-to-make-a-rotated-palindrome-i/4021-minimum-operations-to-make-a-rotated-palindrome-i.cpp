class Solution {
public:
    int minOperations(string s) {
        int ans=INT_MAX;
        string tmp= s+s;
        int len=s.length();
        for(int i=0;i<len;++i){
            int cnt=i;
            int left=i;
            int right=i+len-1;
            while(left<=right){
                if(tmp[left]!=tmp[right]){
                    int diff=abs(tmp[left]-tmp[right]);
                    cnt+=min(diff,26-diff);
                }
                left++;
                right--;
            }
            if(cnt<ans){
                ans=cnt;
            }

        }
        return ans;
    }
};