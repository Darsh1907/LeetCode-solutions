int max(int a, int b){
    if(a>=b) return a;
    return b;
}

int longestMonotonicSubarray(int* nums, int numsSize) {
    int maxLength = 1;
    int incLength = 1;
    int decLength = 1;
    for (int i=1; i<numsSize; i++) {
        // If the current element is greater than the previous one, it's part of an increasing subarray
        if (nums[i] > nums[i-1]) {
            incLength++;
            decLength = 1; // Reset the decreasing subarray length
        }
        // If the current element is smaller than the previous one, it's part of a decreasing subarray
        else if (nums[i] < nums[i-1]) {
            decLength++;
            incLength = 1; // Reset the increasing subarray length
        }
        // If the current element is equal to the previous one, reset both lengths
        else {
            incLength = 1;
            decLength = 1;
        }
        // Update the maxLength with the maximum of current maxLength and either incLength or decLength
        maxLength = max(maxLength, max(incLength, decLength));
    }
    return maxLength;
}