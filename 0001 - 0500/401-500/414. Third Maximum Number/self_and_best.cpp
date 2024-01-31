int thirdMax(int* nums, int numsSize) {
    int max = nums[0];
    long sec_max = LONG_MIN;
    long thir_max = LONG_MIN;
    for(int i=1; i<numsSize; i++){
        if(nums[i]>max){
            thir_max = sec_max;
            sec_max = max;
            max = nums[i];
        }
        else if(nums[i]>sec_max && nums[i]<max){
            thir_max = sec_max;
            sec_max = nums[i];
        }
        else if(nums[i]>thir_max && nums[i]<sec_max) thir_max = nums[i];
    }
    if(thir_max == LONG_MIN) return max;
    int result = thir_max;
    return result;
}