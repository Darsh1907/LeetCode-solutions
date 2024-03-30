int min(int a, int b){ if(a<=b) return a; return b;}

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    if(k==0) return 1;
    int n = numsSize;
    int minLength = 51;
    int left = 0, right = 0;
    int currentOR = 0;
    while (right < n) {
        currentOR |= nums[right];
        while (currentOR >= k) {
            minLength = min(minLength, right - left + 1);
            left++;
            currentOR = 0;
            right = left-1;
        }
        right++;
    }
    if(minLength==51) return -1;
    return minLength;
}