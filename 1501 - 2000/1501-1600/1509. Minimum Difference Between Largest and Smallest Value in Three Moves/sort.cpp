// Hint:
// The minimum difference possible is obtained by removing three elements 
// between the three smallest and three largest values in the array.

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        // if n is less than equal to 3, we can convert every number to 0 and hence the ans = 0.
        // if n==4 we can convert 3 numbers into the 4th number, hence again the ans = 0.
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        // Essentially we can do only 4 things:
        // 1. Remove all 3 from left
        int range1 = nums[n-1]-nums[3];
        // 2. Remove 2 from left and 1 from right;
        int range2 = nums[n-2]-nums[2];
        // 3. Remove 1 from left and 2 from right
        int range3 = nums[n-3]-nums[1];
        // 4. Remove all 3 from right
        int range4 = nums[n-4]-nums[0];
        // Return the minimum of these values
        return min(min(range1, range2), min(range3, range4));
    }
};