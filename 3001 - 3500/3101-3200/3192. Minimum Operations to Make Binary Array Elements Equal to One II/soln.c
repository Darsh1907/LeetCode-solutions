int minOperations(int* nums, int numsSize) {
    int ans = 0;
    int times = 0;
    for(int i=0; i<numsSize; i++) {
        if((nums[i]==1 && times%2==1) || (nums[i]==0 && times%2==0)) {
            times++;
        }
    }
    return times;
}