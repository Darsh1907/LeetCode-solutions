class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Step 1: Find the length of the array.
        int n = nums.size();
        // Step 2: Calculate the actual sum using mathematical formula.
        long actualSum = (long)n * (n + 1) / 2;
        // Step 3: Calculate the given sum.
        long sum = 0;
        for (int element : nums) sum += element;
        // Step 4: Return the difference between the actual and given sums.
        return (int)(actualSum - sum); 
    }
};