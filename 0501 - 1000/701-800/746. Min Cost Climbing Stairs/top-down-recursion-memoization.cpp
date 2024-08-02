class Solution {
    int solve(vector<int>& cost, int n, vector<int>& dp) {
        if(dp[n] != -1) return dp[n];
        dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        return min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    }
};