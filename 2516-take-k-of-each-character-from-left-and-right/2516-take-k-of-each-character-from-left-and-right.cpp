class Solution {
public:
    int takeCharacters(string s, int k) {
        int cnt[3]={0};
        int ans=INT_MIN;
        for(int i=0;i<s.size();++i){
            if(s[i]=='a'){
                cnt[0]++;
            }
            else if(s[i]=='b'){
                cnt[1]++;
            }
            else{
                cnt[2]++;
            }
        }
        if(cnt[0]<k||cnt[1]<k||cnt[2]<k){
            return -1;
        }
        int left=0;
        cnt[0]-=k;
        cnt[1]-=k;
        cnt[2]-=k;
        for(int right=0;right<s.size();++right){
            if(s[right]=='a'){
                cnt[0]--;
            }
            else if(s[right]=='b'){
                cnt[1]--;
            }
            else{
                cnt[2]--;
            }
            while(cnt[0]<0||cnt[1]<0||cnt[2]<0){
                if(s[left]=='a'){
                    cnt[0]++;
                }
                else if(s[left]=='b'){
                    cnt[1]++;
                }
                else{
                    cnt[2]++;
                }
                left++;
            }
                ans=max(ans,right-left+1);
            
        }
        return ans==INT_MIN?-1:s.size()-ans;
    }
};