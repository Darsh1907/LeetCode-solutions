int countKDifference(int* nums, int numsSize, int k) {
    int Res=0;
    for(int i=0; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            if((abs(nums[i]-nums[j]))==k) Res++;
        }
    }
    return Res;
}