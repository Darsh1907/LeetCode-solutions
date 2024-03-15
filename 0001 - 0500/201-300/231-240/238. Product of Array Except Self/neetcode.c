// Refer NeetCode video for intuition behind this code:
// https://www.youtube.com/watch?v=bNvIQI2wAjk

/**
 * Note: The returned array must be malloced, assume caller calls free().
*/

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int total = 1;
    int* result = (int*)malloc(sizeof(int) * n);
    result[0]=1;
    // Calculate the product of elements to the left of each element
    for(int i=1; i < n; i++) result[i] = result[i-1] * nums[i-1];
    // Calculate the product of elements to the right of each element and multiply with the left product
    int right = 1;
    for (int i = n - 2; i >= 0; i--) {
        right *= nums[i + 1];
        result[i] *= right;
    }
    // Set the return size
    *returnSize = n;
    return result;
}