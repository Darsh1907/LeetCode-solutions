int findMin(int* nums, int numsSize) {
    if(nums[0]<nums[numsSize-1]) return nums[0];
    int s = 0;
    int e = numsSize-1;
    int mid = s+(e-s)/2;
    while(s < e) {
        if(nums[mid]>=nums[0]) s=mid+1;
        else e=mid;
        mid = s+(e-s)/2;
    }
    return nums[mid]; 
}