int findPeakElement(int* nums, int numsSize) {
    int s=0, e=numsSize-1;
    int mid;
    while(s<e){
        mid = s+(e-s)/2;
        if(nums[mid] < nums[mid+1]) s = mid+1;
        else e = mid;
    }
    return s;
}