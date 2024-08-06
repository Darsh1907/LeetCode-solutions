class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int prev_to_prev = nums[0];
        int prev = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int inc = prev_to_prev + nums[i];
            int exc = prev;
            int ans = max(inc, exc);
            prev_to_prev = prev;
            prev = ans;
        }
        return prev;
    }
};