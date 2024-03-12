void rotate(int* nums, int numsSize, int k) {
    int n=numsSize;
    k = k%n;
    int res[n];
    for(int i=0;i<n;i++) res[(i+k)%n]=nums[i];
    //copy res array into nums
    for(int i=0; i<n; i++) nums[i]=res[i];
}