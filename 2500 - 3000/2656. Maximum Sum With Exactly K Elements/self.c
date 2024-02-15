int find_max(int* nums, int numsSize){
    int max = nums[0];
    for(int i=1; i<numsSize; i++){
        if(nums[i]>max) max = nums[i];
    }
    return max;
}

int maximizeSum(int* nums, int numsSize, int k){
    int max_ele = find_max(nums, numsSize);
    int sum = 0;
    while(k) {
        sum = sum + max_ele;
        max_ele = max_ele + 1;
        k--;
    }
    return sum;
}