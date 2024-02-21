// marking every visited number as visited inside the array itself

int findDuplicate(int* nums, int numsSize) {
    for(int i = 0; i<numsSize; i++) {
        int num = abs(nums[i]);
        if(nums[num] < 0) return num;
        nums[num] = -nums[num];
    }
    return -1;
}