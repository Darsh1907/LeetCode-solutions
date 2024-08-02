class Solution {
    int solve(vector<int>& cost, int n) {
        // create dp
        vector<int> dp(n+1);
        // step2: base case analysis
        dp[0] = cost[0];
        dp[1] = cost[1];
        // step3: fill the dp table
        for(int i=2; i<n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        // step4: return the answer
        return min(dp[n-1], dp[n-2]);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost, n);
    }
};