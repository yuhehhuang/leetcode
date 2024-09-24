class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            if (!(i & 1)) {
                dp[i] = dp[i / 2];
            } else {
                dp[i] = dp[i / 2] + 1;
            }
        }
        
        return dp;
    }
};