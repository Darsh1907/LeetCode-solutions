// You can refer to the video: https://www.youtube.com/watch?v=Bk-HxzaooqM

long long min(long long a, long long b) {if(a<=b) return a; return b;}
long long max(long long a, long long b) {if(a>=b) return a; return b;}

long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
    long long res = 0;
    int bad_idx = -1;
    int min_idx = -1;
    int max_idx = -1;
    for(int i=0; i<numsSize; i++){
        if(minK>nums[i] || nums[i]>maxK) bad_idx = i;
        if(nums[i]==minK) min_idx=i;
        if(nums[i]==maxK) max_idx=i;
        res += max(0, min(min_idx, max_idx) - bad_idx);
    }
    return res;
}