class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int maxTime=neededTime[0];//當前最大，偌多個連續一定是當前最大的會活著
        int ans=0;
        for(int i=0;i<colors.size()-1;++i){
            if(colors[i]==colors[i+1]){
                ans+=min(maxTime,neededTime[i+1]);
                maxTime=max(maxTime,neededTime[i+1]);
            }
            else{
                //遇到第一個不同的，把它做更新，始祖老大
                maxTime=neededTime[i+1];
            }
        }
        return ans;
    }
};