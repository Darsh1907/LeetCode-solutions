#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
  int low = 0;
  int high = numsSize - 1;
  while (low <= high) {
    int mid = (low + high)/2;
    if (nums[mid]==target) return mid;
    else if (nums[mid] < target) low=mid+1;
    else high=mid-1;
  }
  return low;
}

int main() {
  // Example usage
  int nums[] = {1, 3, 4, 6};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int target = 7;

  int index = searchInsert(nums, numsSize, target);

  printf("Insert position: %d\n", index);

  return 0;
}