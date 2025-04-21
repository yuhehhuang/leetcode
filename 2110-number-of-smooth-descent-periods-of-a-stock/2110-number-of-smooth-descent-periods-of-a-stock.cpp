class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=1;
        int len=1;
        for(int i=1;i<prices.size();++i){
            if(prices[i-1]-prices[i]==1){
                len++;
            }
            else{
                len=1;
            }
            ans+=len;
        }
        return ans;
    }
};