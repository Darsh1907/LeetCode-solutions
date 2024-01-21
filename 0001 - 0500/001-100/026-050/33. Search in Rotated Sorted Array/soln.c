#include<stdio.h>

int lower_pivot(int* nums, int numsSize) {
    int s = 0;
    int e = numsSize - 1;
    int mid = s + (e - s) / 2;
    while (s < e) {
        if (nums[mid] >= nums[0])
            s = mid + 1;
        else
            e = mid;
        mid = s + (e - s) / 2;
    }
    return s; // Can return e as well
}

int vanilla_bin_search(int* nums, int s, int e, int target) {
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (nums[m] == target)
            return m;
        if (target > nums[m])
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    int low_pivot = lower_pivot(nums, numsSize);
    if (target>=nums[low_pivot] && target<=nums[numsSize-1])
        return vanilla_bin_search(nums, low_pivot, numsSize-1, target);  
    else
        return vanilla_bin_search(nums, 0, low_pivot-1, target);
}

int main(){
    int arr1[7] = {4,5,6,7,0,1,2};
    int target1 = 0;

    int arr2[7] = {4,5,6,7,0,1,2};
    int target2 = 3;

    int arr3[1] = {1};
    int target3 = 0;

    printf("%d\n", search(arr1, 7, target1));
    printf("%d\n", lower_pivot(arr1, 7));
    printf("%d\n", search(arr1, 7, target2));
    printf("%d\n", search(arr1, 1, target3)); 
}