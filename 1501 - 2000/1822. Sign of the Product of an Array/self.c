int arraySign(int* nums, int numsSize) {
    int neg_count = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i]<0) neg_count++;
        else if (nums[i]==0) return 0;
    }
    if(neg_count%2 == 0) return 1;
    return -1;
}