int majorityElement(int* nums, int numsSize) {
    int res=nums[0];
    int count=1;
    for(int i=1; i<numsSize; i++){
        if(nums[i]==res) count++;
        else if(nums[i]!=res) count--;
        if(count==0) res=nums[i+1];
    }
    return res;
}