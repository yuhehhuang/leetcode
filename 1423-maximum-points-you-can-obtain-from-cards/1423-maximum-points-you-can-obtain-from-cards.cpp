class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //k=>0
        //k+1==>1
        int size=cardPoints.size();
        int sum=0;
        int ans;
        for(int i=size-k;i<size;i++){
            sum+=cardPoints[i];
        }
        ans=sum;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i] - cardPoints[size - k + i];
            ans = max(ans, sum);
        }
        return ans;
    }
};