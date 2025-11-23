#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        // dp[i][r] = maximum sum achievable using the first i elements (i in [0..n]) such that (sum % 3) == r.
        // Use (n+1) rows so dp[0] is the base (no elements).
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));
        // Base case: using 0 elements, sum 0 is possible and has remainder 0.
        dp[0][0] = 0;
        dp[0][1] = INT_MIN; // unreachable
        dp[0][2] = INT_MIN; // unreachable
        // Fill the table row by row
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];       // current number (1-based dp row vs 0-based nums)
            int xr = x % 3;           // remainder of current number
            // First, copy the "skip" option: we can always skip current number
            // and carry forward all remainders from previous row.
            for (int r = 0; r < 3; ++r) {
                dp[i][r] = dp[i - 1][r];
            }
            // Now consider taking the current number.
            // We must only create transitions from reachable previous remainders.
            for (int prev_r = 0; prev_r < 3; prev_r++) {
                if (dp[i - 1][prev_r] == INT_MIN) {
                    continue; // previous remainder not reachable -> skip
                }
                // If we take x, the new remainder becomes (prev_r + xr) % 3
                int new_r = (prev_r + xr) % 3;
                // Update dp[i][new_r] with the sum formed by adding x to dp[i-1][prev_r]
                dp[i][new_r] = max(dp[i][new_r], dp[i - 1][prev_r] + x);
            }
        }
        // Answer: best sum using all n elements with remainder 0 (divisible by 3).
        // dp[n][0] is at least 0 because of the empty subset.
        return dp[n][0];
    }
};