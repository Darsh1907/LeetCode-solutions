class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int s=n-1; s>=0; s--) {
            for(int e=s+2; e<n; e++) {
                int ans = INT_MAX;
                for(int k=s+1; k<e; k++) {
                    ans = min(ans, values[s]*values[k]*values[e] + dp[s][k] + dp[k][e]);
                }
                dp[s][e] = ans;
            }
        }
        return dp[0][n-1];
    }
};