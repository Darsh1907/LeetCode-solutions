int* twoSum(int* nums, int numbersSize, int target, int* returnSize){
    int i=0;
    int j=numbersSize-1;
    while(i<j){
        if(nums[i]+nums[j]>target) j--;
        else if(nums[i]+nums[j]<target) i++;
        else if(nums[i]+nums[j]==target){
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = i + 1;
            result[1] = j + 1;
            *returnSize = 2;
            return result;
        }
    }
    return NULL;
}