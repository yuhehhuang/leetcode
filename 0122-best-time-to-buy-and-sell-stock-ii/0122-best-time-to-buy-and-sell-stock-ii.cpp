class Solution {
public:
//假如第 0 天买入，第 3 天卖出，那么利润为：prices[3] - prices[0]。
//相当于(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])。
//那麼到第N天的最大值獲利=(pirces[n]-prices[n-1])+....+(prices[1]-prices[0])
//那我只要這些式子中只取>0的部分 那肯定是最佳解 --->Funcking Genius


    int maxProfit(vector<int>& prices) {
        int result=0;
        for(int i=1;i<prices.size();i++){
            result+=max(prices[i]-prices[i-1],0);
        }
        return result;
    }
};