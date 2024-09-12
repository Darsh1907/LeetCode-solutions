class Solution {
private:
    int solve(vector<int>& v, int s, int e, vector<vector<int>>& dp) {
        if(s+1 == e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int ans = INT_MAX;
        for(int i=s+1; i<e; i++) {
            ans = min(ans, v[s]*v[i]*v[e] + solve(v, s, i, dp) + solve(v, i, e, dp));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(values, 0, n-1, dp);
    }
};