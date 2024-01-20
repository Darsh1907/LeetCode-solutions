#include<stdio.h>
#include <stdbool.h>

// Logic is that there maximum only one such pair such that
// the previous number is greater than the next number in case of a rotated sorted array 
// (including the end positions)

bool check(int* nums, int numsSize) {
    int count = 0;
    for(int i=1; i<numsSize; i++){
        if(nums[i-1]>nums[i]) count++;
        if(count>1) return false;
    }
    if(nums[numsSize-1]>nums[0]) count++;
    return count<=1;
}

int main(){
    int arr1[5] = {3,4,5,1,2};
    int arr2[4] = {2,1,3,4};
    int arr3[3] = {1,2,3};
    printf("%d\n", check(arr1, 5));
    printf("%d\n", check(arr2, 4));
    printf("%d", check(arr3, 3));
}