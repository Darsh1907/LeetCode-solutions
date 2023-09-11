/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    if (numsSize <= 1) {
        *returnSize = numsSize;
        return nums;
    }
    int* result = (int*)malloc(numsSize * sizeof(int)); // Allocate memory for the result array
    if (result == NULL) {
        // Handle memory allocation error
        *returnSize = 0;
        return NULL;
    }
    result[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] + nums[i];
    }
    *returnSize = numsSize;
    return result;
}