int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int n = numsSize + 1;
    int *arr = (int *)malloc(n * sizeof(int));
    int *a = (int *)malloc(n * sizeof(int));
    // Initialize the 'a' array
    for(int i=0; i<n; i++) a[i]=0;
    // Count occurrences of elements in 'nums' in the 'a' array
    for (int i=0; i<numsSize; i++) {
        if(nums[i]<n) a[nums[i]]++;
    }
    int k = 0;
    // Store duplicates in 'arr'
    for(int i=0; i<n; i++) {
        if(a[i]>1) {
            arr[k] = i;
            k++;
        }
    }
    // Free the memory allocated for 'a'
    free(a);
    *returnSize = k;
    return arr;
}