long long countAlternatingSubarrays(int* nums, int numsSize) {
    long long count=0;
    int l = 0;
    int r = 0;
    while(r < numsSize){
        if(r>0 && nums[r]==nums[r-1]) l=r;
        count += (r-l+1);
        r++;
    }
    return count;
}