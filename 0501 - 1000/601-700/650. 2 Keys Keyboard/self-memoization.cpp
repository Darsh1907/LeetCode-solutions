// Hint1: How many characters may be there in the clipboard at the last step if n = 3? n = 7? n = 10? n = 24?

class Solution {
    int solve(const int& n, int curr_count, int curr_copy, vector<vector<int>>& dp) {
        // Base case
        if (curr_count == n) return 0;
        if (curr_count > n) return INT_MAX;
        // Check if present in dp
        if (dp[curr_count][curr_copy] != -1) return dp[curr_count][curr_copy];
        // If not present in dp
        int copy_paste = solve(n, curr_count + curr_count, curr_count, dp);
        int paste;
        if(curr_copy > 0) paste = solve(n, curr_count + curr_copy, curr_copy, dp);
        // Option 1: Copy and Paste
        if(copy_paste < INT_MAX-2) copy_paste += 2;
        // Option 2: Paste the already copied As
        if(paste < INT_MAX-1) paste += 1;
        // Add to DP
        dp[curr_count][curr_copy] = min(copy_paste, paste);
        return dp[curr_count][curr_copy];
    }
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); // dp[curr_count][curr_copy]
        return solve(n, 1, 0, dp); // Start with 1 A and no copied A
    }
};