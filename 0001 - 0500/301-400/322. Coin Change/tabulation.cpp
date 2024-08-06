// Striver: https://www.youtube.com/watch?v=myPeWb3Y68A

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        // Initialize the first row of the DP table
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9; // Set it to a very large value if not possible
        }
        // Fill the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                // Calculate the minimum elements needed without taking the current element
                int notTake = dp[ind - 1][target];
                // Calculate the minimum elements needed by taking the current element
                int take = 1e9; // Initialize 'take' to a very large value
                if(coins[ind] <= target) take = 1 + dp[ind][target - coins[ind]];
                // Store the minimum of 'notTake' and 'take' in the DP table
                dp[ind][target] = min(notTake, take);
            }
        }
        // The answer is in the bottom-right cell of the DP table
        int ans = dp[n-1][amount];
        // If 'ans' is still very large, it means it's not possible to form the target sum
        if (ans >= 1e9) return -1;
        return ans; // Return the minimum number of elements needed
    }
};