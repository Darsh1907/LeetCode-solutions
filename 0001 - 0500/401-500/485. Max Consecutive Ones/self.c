int findMaxConsecutiveOnes(int* nums, int n){
    int count=0;
    int maxcount=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==1)
        count++;
        else
        count=0;
        if(count>maxcount)
        maxcount=count;
    }
    return maxcount;
}