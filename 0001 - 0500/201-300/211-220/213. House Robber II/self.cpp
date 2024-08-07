// Hint1:
// Since House[1] and House[n] are adjacent, they cannot be robbed together. 
// Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. 
// Now the problem has degenerated to the House Robber, which is already been solved.

class Solution {
    int robUtil(vector<int>& nums) {
        int n = nums.size();
        int prev_to_prev = nums[0];
        int prev = max(nums[0], nums[1]);
        for(int i=2; i<n; i++) {
            int inc = prev_to_prev + nums[i];
            int exc = prev;
            int ans = max(inc, exc);
            prev_to_prev = prev;
            prev = ans;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        int temp = nums.back();
        nums.pop_back();
        int robfirst = robUtil(nums);
        nums.push_back(temp);
        nums.erase(nums.begin());
        int roblast = robUtil(nums);
        return max(robfirst, roblast);
    }
};