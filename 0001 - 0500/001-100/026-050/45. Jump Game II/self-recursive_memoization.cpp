class Solution {
    int count(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind >= nums.size()-1) return 0;
        if(dp[ind] != -1) return dp[ind];
        int ans = INT_MAX;
        for(int i=1; i<=nums[ind]; i++) {
            int newind = ind + i;
            if(newind >= nums.size()) break;
            int jumps = count(nums, newind, dp);
            if(jumps != INT_MAX) ans = min(ans, jumps + 1);
        }
        dp[ind] = ans;
        return dp[ind];
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[nums.size()-1] = 0;
        return count(nums, 0, dp);
    }
};