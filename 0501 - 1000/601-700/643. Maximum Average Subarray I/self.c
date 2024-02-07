double findMaxAverage(int* nums, int numsSize, int k) {
    if (numsSize < k) return -1;
    int l = 0;
    int r = 0;
    double max_avg = INT_MIN;
    double avg = 0.0;
    double sum = 0;
    while (r < k) {
        sum += nums[r];
        r++;
    }
    avg = sum/k;
    if (avg > max_avg) max_avg = avg;
    while (r < numsSize) {
        sum -= nums[l++];
        sum += nums[r++];
        avg = sum/k;
        if (avg > max_avg) max_avg = avg;
    }
    return max_avg;
}