// Simple Binary Search approach

bool allocate(int* nums, int numsSize, int k, int mid) {
    int kcount=1, ksum=0;
    for(int i=0; i<numsSize; i++) {
        if(ksum+nums[i] <= mid) ksum+=nums[i];
        else {
            kcount++;
            if(kcount>k || nums[i]>mid) return false;
            ksum=nums[i];
        }
    }
    return true;
}

int splitArray(int* nums, int numsSize, int k) {
    int ans = -1, s=0, e=0;
    for(int i=0; i<numsSize; i++) e+=nums[i];
    int mid=s+(e-s)/2;
    while(s<=e) {
        if(allocate(nums, numsSize, k, mid)) {
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
        mid = s+(e-s)/2;
    }
    return ans;
}