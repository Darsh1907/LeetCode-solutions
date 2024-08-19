class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        // for every element of dp
        for(int i=1; i<=n; i++) {
            // explore all the possible squares that can be added
            for(int j=1; j*j<=n; j++) {
                int temp = j*j;
                if(i-temp >= 0) dp[i] = min(dp[i], 1 + dp[i-temp]);
            }
        }
        return dp[n];
    }
};