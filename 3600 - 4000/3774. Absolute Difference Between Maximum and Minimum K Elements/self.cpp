class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int smallestSum = 0, largestSum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            smallestSum += nums[i];
            largestSum += nums[n-1-i];
        }
        return abs(largestSum - smallestSum);
    }
};