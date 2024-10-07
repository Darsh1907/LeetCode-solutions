class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // The farthest index we can reach
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if(i > maxReach) return false;  // If we can't reach this index
            maxReach = max(maxReach, i+nums[i]);  // Update the farthest index we can reach
            if(maxReach >= n-1) return true;  // We can reach or exceed the last index
        }
        return false;  // If we finish the loop and haven't reached the end
    }
};