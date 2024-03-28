int pivotIndex(int* nums, int numsSize) {
    int totalSum=0;
    int leftSum=0;
    for(int i=0; i<numsSize; i++) totalSum+=nums[i];
    for(int i=0; i<numsSize; i++){
        int rightSum=totalSum-nums[i]-leftSum;
        if(leftSum==rightSum) return i;
        else leftSum+=nums[i];
    }
    return -1;
}