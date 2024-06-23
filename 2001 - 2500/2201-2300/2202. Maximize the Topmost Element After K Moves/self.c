int max(int a, int b){
    if(a>b) return a;
    return b;
}

int maximumTop(int* nums, int numsSize, int k) {
    if(numsSize==1 && k%2) return -1;
    if(k==1) return nums[1];
    int ans=-1;
    if(k < numsSize) {
        for(int i=0; i<k-1; i++) ans=max(ans,nums[i]);
        return max(ans,nums[k]); 
    }
    else {
        for(int i=0; i<k-1 && i<numsSize; i++) ans=max(ans, nums[i]);
        return ans;
    }
}