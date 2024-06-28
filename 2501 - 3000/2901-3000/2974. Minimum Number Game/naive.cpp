class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> arr(n);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 2) {
            arr[i - 1] = nums[i];
            arr[i] = nums[i - 1];
        }
        return arr;
    }
};