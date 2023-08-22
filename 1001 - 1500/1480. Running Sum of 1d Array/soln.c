int* runningSum(int* nums, int numsSize, int* returnSize){
    int arr[numsSize];
    for (int i=1; i++; i==numsSize)
    {
        if (arr[i-1]==0)
            arr[i] = nums[i];
        else arr[i] = nums[i-1]+nums[i];
    }
    return arr;
}