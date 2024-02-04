int returnToBoundaryCount(int* nums, int numsSize) {
    int count = 0;
    int sum = 0;
    for(int i=0; i<numsSize; i++){
        sum = sum + nums[i];
        if(sum==0) count++;
    }
    return count;
}