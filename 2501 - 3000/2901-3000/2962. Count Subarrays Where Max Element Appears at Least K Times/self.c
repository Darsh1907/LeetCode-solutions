long long max_ele(int* nums, int numsSize) {
    long long max_ele = nums[0];
    for(int i=1; i<numsSize; i++) {
        if(nums[i]>max_ele) max_ele = nums[i];
    }
    return max_ele;
}

// counts subarrays with occurence of the max_ele atmost (k-1) times
long long count_help(int* nums, int numsSize, int k, long long max) {
    long long result = 0;
    long long freq = 0;
    long long l=0, r=0;
    while(r < numsSize) {
        if(nums[r]==max) freq++;
        while(freq > k){
            if(nums[l]==max) freq--;
            l++;
        }
        result = result + r - l + 1;
        r++;
    }
    return result;
}

long long countSubarrays(int* nums, int numsSize, int k) {
    long long max = max_ele(nums, numsSize);
    long long total = numsSize;
    total = total * (numsSize+1)/2;
    long long result = total - count_help(nums, numsSize, k-1, max);
    return result;
}