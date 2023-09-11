int findNumbers(int* nums, int numsSize){
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        if((nums[i]<100) && (nums[i]>9))
            count+=1;
        if((nums[i]>999) && (nums[i]<10000))
            count+=1;
        if((nums[i]>99999)&&(nums[i]<1000000))
            count+=1;
    }
    return count;    
}