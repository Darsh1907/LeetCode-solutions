int findDuplicate(int* nums, int numsSize) {
    int low = 1, high = numsSize-1, cnt;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        cnt = 0;
        for(int i=0; i<numsSize; i++) {
            if(nums[i] <= mid) cnt++;
        }
        // binary search on left
        if(cnt <= mid) low = mid + 1;
        // binary search on right
        else high = mid - 1;
    }
    return low;
}