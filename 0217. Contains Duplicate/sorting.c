int compare(void * a, void * b)
{
    int aVal = *(int *) a;
    int bVal = *(int *) b;
    return aVal - bVal;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), &compare);
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == nums[i-1]) return true;
    }
    return false;
}