class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return 1;
        vector<int> preSum(n+1);
        int tmpSum=0;
        for(int i=1;i<=n;i++){
            tmpSum+=i;
            preSum[i]=tmpSum;
        }
        int sum=n;
        for(int i=n-1;i>0;i--){
            sum+=i;
            if(sum==preSum[i]){
                return i;
            }
        }
        return -1;
    }
};