class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // If there are no houses, the maximum amount robbed is 0.
        if (n == 1) return nums[0];  // If there is only one house, rob it.
        vector<int> dp(n, 0);
        dp[0] = nums[0];  // Base case: only one house to rob.
        for(int i=1; i<n; i++) {
            int inc = (i>1 ? dp[i-2] : 0) + nums[i];  // Maximum amount if we rob the current house.
            int exc = dp[i-1];  // Maximum amount if we do not rob the current house.
            dp[i] = max(inc, exc);
        }
        return dp[n-1];  // Maximum amount robbed up to the last house.
    }
};