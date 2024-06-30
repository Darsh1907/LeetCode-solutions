int minOperations(int* nums, int numsSize) {
    int ans = 0;
    for(int i=0; i<numsSize-2; i++) {
        if(nums[i]==1) continue;
        for(int j=i; j<=i+2; j++) nums[j] = nums[j] ^ 1;
        ans++;
    }
    if(nums[numsSize-1]==0 || nums[numsSize-2]==0) return -1;
    return ans;
}