class Solution {
    bool isPossible(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind >= nums.size()-1) return true;
        if(dp[ind] != -1) return dp[ind];
        bool pos = false;
        for(int i=1; i<=nums[ind]; i++) {
            int newind = ind + i;
            if(newind >= nums.size()) break;
            pos = isPossible(nums, newind, dp);
            if(pos) {
                dp[newind] = 1;
                return true;
            }
        }
        dp[ind] = 0;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1); // -1->not calculated, 0->false, 1->true
        dp[nums.size()-1] = 1;
        int index = 0;
        return isPossible(nums, index, dp);
    }
};