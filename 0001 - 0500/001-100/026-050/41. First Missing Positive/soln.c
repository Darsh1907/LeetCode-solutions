int firstMissingPositive(int* nums, int numsSize) {
    // Note that the missing positive would only be between [1, nums.size()+1] (neetcode explained)
    for(int i=0; i<numsSize; i++) {
        // Replacing every non-elgible number by another non-eligible number i.e, numsSize+2
        if(nums[i]<=0) nums[i]=numsSize+2;
    }
    for(int i=0; i<numsSize; i++) {  // Mark negative in the array for the numbers which are present in the array
        int abs_val = abs(nums[i]);
        if(abs_val<=numsSize){
            if(nums[abs_val-1] > 0) nums[abs_val-1] = nums[abs_val-1] * -1;
        }
    } 
    for(int i=0; i<numsSize; i++) { // Check the first positive number that has not occured in the array
        if(nums[i]>0) return i+1;
    }
    return numsSize+1;
}