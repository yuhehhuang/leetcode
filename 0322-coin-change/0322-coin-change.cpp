class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    vector<long>v(amount+1, INT_MAX);
        v[0] = 0;
        for(int j=0;j<amount+1;j++){
            for(int i=0;i<coins.size();i++){
                if(coins[i]<=j)
                //min(v[j]->在背包為j的情況下用index 0~i-1的結果中最好的,用coins[j]的最佳解)
                v[j]=min(v[j],v[j-coins[i]]+1);
            }
        }
        return v[amount] == INT_MAX ? -1 : v[amount];
    }
};