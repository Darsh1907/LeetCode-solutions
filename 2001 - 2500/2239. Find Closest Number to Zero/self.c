int findClosestNumber(int* nums, int numsSize) {
    int min_dist = abs(nums[0]);
    int result = nums[0];
    for(int i=0; i<numsSize; i++){
        if(abs(nums[i])<min_dist || (abs(result)==nums[i])){
            min_dist = abs(nums[i]);
            result = nums[i];
        }
    }
    return result;
}