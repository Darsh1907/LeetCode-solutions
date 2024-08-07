class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        int dpr = 0, res = 0;
        for(int i = nums.size() - 2; i >= 0; i--) {
            int temp = res;
            res = max(res, nums[i] + dpr);
            dpr = temp;
        }
        
        int dpr2 = 0, res2 = 0;
        for(int i = nums.size() - 1; i > 0; i--) {
            int temp = res2;
            res2 = max(res2, nums[i] + dpr2);
            dpr2 = temp;
        }

        return max(res, res2);
    }
};