int maxSubArray(int* nums, int numsSize) {
    // Initialize maxSum as an integer that cannot store any value below the limit...
    int maxSum = nums[0];
    // Initialize maxSumSoFar as 0...
    int maxSumSoFar = 0;
    // Traverse all the elements...
    for(int i = 0; i < numsSize; i++){
        // Keep adding the current value...
        maxSumSoFar += nums[i];
        // Update maxSum to the max of maxSum and maxSumSoFar...
        if(maxSum < maxSumSoFar) maxSum = maxSumSoFar;
        // if maxSumSoFar is less than 0 then update it to 0...
        if(maxSumSoFar < 0) maxSumSoFar = 0;
    }
    return maxSum;      // Return the contiguous subarray which has the largest sum...
}