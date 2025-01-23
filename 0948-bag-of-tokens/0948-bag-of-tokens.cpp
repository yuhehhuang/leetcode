class Solution {
public:
//盡量用power買便宜的，直到power不夠後，用score去換最大的 然後繼續買。
//left:準備要買的
//right:準備要賣的
//所以說同一個商品有可能要買或賣(while(left<=right))
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
