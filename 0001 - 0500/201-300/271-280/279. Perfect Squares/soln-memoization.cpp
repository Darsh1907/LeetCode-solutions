class Solution {
    int solve(int n, vector<int>& dp) {
        // check in dp first
        if(dp[n]!=-1) return dp[n];
        // if not present in dp
        int ans = n;
        for(int i=1; i*i<=n; i++) {
            ans = min(ans, 1 + solve(n-i*i, dp));
        }
        dp[n] = ans;
        return dp[n];
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        return solve(n, dp);
    }
};