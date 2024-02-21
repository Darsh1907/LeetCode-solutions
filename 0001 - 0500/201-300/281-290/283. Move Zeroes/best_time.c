void swap(int *a,int *b){
    if(*a != *b){
        int temp = *b;
        *b = *a;
        *a = temp;
    }
}
void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    int j = 0;
    while(i < numsSize){
        if(nums[i]==0) i++;
        else {
            swap(&nums[i],&nums[j]);
            i++;
            j++;
        }
    }
}