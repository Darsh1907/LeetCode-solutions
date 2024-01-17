void moveZeroes(int* nums, int numsSize) {
    int non_zer_index = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i]!=0){
            nums[non_zer_index] = nums[i];
            non_zer_index++;
        }
    }
    for(int i=non_zer_index; i<numsSize; i++) nums[i]=0; 
}