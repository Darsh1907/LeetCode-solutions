int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if(k==0) return 0;
    int product=1, cnt=0;
    int l=0, r=0;
    while(r < numsSize) {
        product *= nums[r++];
        while(l<r && product>=k) product/=nums[l++];
        cnt += (r-l);
    }
    return cnt;
}