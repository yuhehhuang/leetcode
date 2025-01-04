class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        //兩次slide window
        int left_T=0;
        int left_F=0;
        int cnt=k;
        int ansx=0;
        for(int right=0;right<ans.size();++right){
            if(ans[right]=='F'){
                cnt--;
            }
            while(cnt<0){
                if(ans[left_T]=='F'){
                    cnt++;
                }
                left_T++;
            }
            ansx=max(ansx,right-left_T+1);
        }
        for(int right=0;right<ans.size();++right){
            if(ans[right]=='T'){
                k--;
            }
            while(k<0){
                if(ans[left_F]=='T'){
                    k++;
                }
                left_F++;
            }
            ansx=max(ansx,right-left_F+1);
        }
        return ansx;
    }
};