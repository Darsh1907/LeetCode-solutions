/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    // Calculate the size of the concatenated array
    *returnSize = 2 * numsSize;
    // Allocate memory for the concatenated array
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    // Copy the elements of nums to ans
    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }
    return ans;
}