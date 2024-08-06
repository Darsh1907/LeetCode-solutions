class Solution {
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
        // base case - index is out of range
        if(ind>=nums.size()) return 0;
        // check in DP
        if(dp[ind] != -1) return dp[ind];
        // include
        int inc = nums[ind] + solve(nums, ind+2, dp);
        // exclude
        int ex = solve(nums, ind+1, dp);
        // put in DP
        dp[ind] = max(inc, ex);
        return dp[ind];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int n = nums.size();
        int ans = solve(nums, 0, dp);
        return ans;
    }
};