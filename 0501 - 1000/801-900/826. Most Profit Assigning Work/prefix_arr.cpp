// This solution can named as both prefix array and DP.

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        int maxEle = *max_element(difficulty.begin(), difficulty.end());
        vector<int> dp(maxEle+1, 0);
        for(int i=0; i<n; i++) dp[difficulty[i]] = max(dp[difficulty[i]], profit[i]);
        for(int i=1; i<=maxEle; i++) dp[i] = max(dp[i], dp[i-1]);
        int profSum = 0;
        for(int i=0; i<m; i++) {
            if(worker[i] <= maxEle) profSum += dp[worker[i]];
            else profSum += dp[maxEle];
        }
        return profSum;
    }
};