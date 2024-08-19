class Solution {
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        // Base Case
        if (target < 0) return 0;
        // Check in dp
        if (dp[target] != -1) return dp[target];
        // Add every num in nums one by one and call the recursive func
        int ans = 0;
        for(int num : nums) ans += solve(nums, target-num, dp);
        dp[target] = ans;
        return dp[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 1;
        return solve(nums, target, dp);
    }
};