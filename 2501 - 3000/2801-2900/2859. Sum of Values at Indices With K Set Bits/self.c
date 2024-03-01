int sumIndicesWithKSetBits(int* nums, int numsSize, int k){
    int sum = 0;
    for(int i=0; i<numsSize; i++){
        if(k == __builtin_popcount(i)) sum += nums[i];
    }
    return sum;
}