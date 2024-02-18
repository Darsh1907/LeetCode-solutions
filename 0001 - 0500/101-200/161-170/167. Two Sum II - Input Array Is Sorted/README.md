# 167. Two Sum II - Input Array Is Sorted (Medium)

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
 

Example 1:
```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```
Example 2:
```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```
Example 3:
```
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

Constraints:
```
1. 2 <= numbers.length <= 3 * 104
2. -1000 <= numbers[i] <= 1000
3. numbers is sorted in non-decreasing order.
4. -1000 <= target <= 1000
5. The tests are generated such that there is exactly one solution.
```

# Solution

## Intuition
To utilize the fact that the array is sorted to our advantage.

## Approach
We keep two pointers.
<br>
i is the left pointer. initialised to 0(start of the array).
j is the right pointer. initialised to size-1 (end of the array).
<br>
Check the sum of numbers pointed by both the pointers:
Case1: If the sum < target, it means we need to try getting a larger sum. To achieve that, we will increase the left pointer by one position and keep the right pointer as it is.
Case2: If the sum > target, it means we need to try getting a smaller sum. To achieve that, we will decrease the right pointer by one position and keep the left pointer as it is.
Case3: We get sum == target. In that case, we return i+1 and j+1 cuz the question asks us to return index position as per 1-ordered indexing.

## Complexity
- Time complexity:
Worst case complexity will be O(n).

- Space complexity:
O(1) as only two additional variables are used.

## Code
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]>target) j--;
            else if(nums[i]+nums[j]<target) i++;
            else if(nums[i]+nums[j]==target) return {i+1, j+1};
        }
        return {0};
    }
};
```