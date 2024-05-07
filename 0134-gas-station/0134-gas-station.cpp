class Solution {
public:
// 把這個圖畫成一個環形圖，前進方向為順時針。假設totalsum=0，那麽走一圈油量和消耗抵消下來就為0（先不管油夠不夠走到每一站），假設從起點到第i點油量不夠消耗，那麽從i點繼續走回起點油量就肯定大於消耗，因為總油量和消耗相等。那麽答案很明顯了，我既然從起點順時針走到i點又不夠，那我從i點順時針走回起點油就夠了
//for會一直更新 所以會找到最大的i使0走到i的消耗>成本 故 i+1走到0的成本>消耗 
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0,total_cost=0;
        int cur_gas=0,starting_point=0;
        for(int i=0;i<gas.size();i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
            //以上用來算是否有解
            //以下用來找唯一解
            cur_gas+=gas[i]-cost[i];
            if(cur_gas<0){
                starting_point=i+1;
                cur_gas=0;//reset
            }
        }
        return(total_gas<total_cost)?-1:starting_point;
    }
};