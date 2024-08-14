// Hint 1: Binary search for the answer. How can you check how many pairs have distance <= X?
// https://www.youtube.com/watch?v=bQ-QcFKwsZc

class Solution {
    int getPairs(const vector<int>& nums, int dist) {
        int l = 0, r = 0;
        int res = 0;
        while (r < nums.size()) {
            while (nums[r] - nums[l] > dist) l++;
            res += r - l;
            r++;
        }
        return res;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.back() - nums[0];
        // binary search logic
        while (l < r) {
            int m = l + (r - l) / 2;
            int pairs = getPairs(nums, m);
            if (pairs >= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};