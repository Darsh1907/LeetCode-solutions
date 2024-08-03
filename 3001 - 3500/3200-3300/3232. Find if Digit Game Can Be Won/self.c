bool canAliceWin(int* nums, int numsSize) {
    int sin_dig = 0;
    int doub_dig = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i]>9) doub_dig += nums[i];
        else sin_dig += nums[i];
    }
    return (sin_dig != doub_dig);
}