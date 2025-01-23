class Solution {
public:
//how to get score : 用power去支付tokens來換取 score+1;
//用小的token來get score 用score 換大的token
//power-token[small]+token[big]>次二小的合才賺
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int left=0;
        int right=tokens.size()-1;
        while(left<=right){
            if(power>=tokens[left]){
                power-=tokens[left++];
                ans++;
            }
            else if(left<right&&ans>0){
                ans--;
                power+=tokens[right--];
            }
            else {
                break;
            }
        }
        return ans;
    }
};