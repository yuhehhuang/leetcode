class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int>ans(cost.size()+1,0);
       ans[0]=0;
       ans[1]=0;
        for(int i=2;i<=cost.size();i++){
            ans[i]=min(ans[i-2]+cost[i-2],ans[i-1]+cost[i-1]);
        }
       return ans[cost.size()];
    }
};