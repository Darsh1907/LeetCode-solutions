int missingNumber(int* nums, int numsSize) {
    long actualSum = numsSize*(numsSize+1)/2;
    long sum = 0;
    for (int i=0; i<numsSize; i++) sum=sum+nums[i];
    return (int)(actualSum - sum); 
}