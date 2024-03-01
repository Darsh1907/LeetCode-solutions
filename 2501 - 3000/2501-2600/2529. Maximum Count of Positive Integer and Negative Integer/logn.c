int maximumCount(int* nums, int numsSize){
    if(nums[0]>0) return numsSize;
    if(nums[numsSize-1]<0) return numsSize;
    int low = 0 ,high = numsSize-1 , mid;
    while(low <= high) {
        mid=(low+high)/2;
        if(nums[mid]<0 ) low = mid+1;
        if(nums[mid]>0) high = mid-1;
        if(nums[mid]==0 || (nums[mid]>0 && nums[mid-1] < 0)) break;
    }
    int neg , pos;
    neg = pos = mid;
    if(nums[mid] == 0) {
        while(neg >0 && nums[neg] == 0) neg--;
        while(pos <numsSize && nums[pos] == 0) pos++;
        if(pos == numsSize && neg == 0) return 0;
        neg++;
    }
    pos = numsSize - pos;
    neg = neg;
    return fmax(neg,pos);
}