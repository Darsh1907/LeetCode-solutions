int findNumbers(int* nums, int numsSize){
    int digit;
    int output = 0;
    for(int i = 0; i < numsSize; i++)
    {
        int number = nums[i];
        digit = 0;
        while(number)
        {
            digit += 1;
            number /= 10;
        }
        if(!(digit & 1)) output++;
    }
    return output;
}