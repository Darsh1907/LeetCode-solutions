int longestOnes(int* nums, int numsSize, int k) {
    int start=0, end, count=0;
    for(end=0; end<numsSize; end++) {
        if(nums[end]==0) count++;
        if(count>k) {
            if(nums[start]==0) count--;
            start++;
        }
    }
    return end-start;
}