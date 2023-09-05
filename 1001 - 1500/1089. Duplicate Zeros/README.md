# 1089. Duplicate Zeros (Easy)

Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

**Note** that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

**Example 1:**
```
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
```
**Example 2:**
```
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
```

**Constraints:**
```
1 <= arr.length <= 104
0 <= arr[i] <= 9
```

# gpt.cpp explanation:

To solve this problem, we can follow these steps: <br>

1. Initialize variables n as the size of the input array arr and zeros to count the number of zeros in the original array.
2. Iterate through the original array to count the number of zeros.
```cpp
for (int num : arr) {
    if (num == 0) zeros++;
}
```
3. Calculate lastIndex as n + zeros - 1. This will be the index of the last element in the modified array after duplicating zeros.

4. Now, we perform a backward traversal of the original array from the end (i = n - 1) and copy elements to their new positions in the modified array: If lastIndex is still within the bounds of the original array, copy the current element at arr[lastIndex]. If the current element is zero, decrement lastIndex and, if it's still within bounds, set arr[lastIndex] to zero. Decrement lastIndex after each iteration.<br>
Here's the code snippet that implements these steps:
```cpp
for (int i = n - 1; i >= 0; i--) {
    if (lastIndex < n) arr[lastIndex] = arr[i];
    if (arr[i] == 0) {
        lastIndex--;
        if (lastIndex < n) arr[lastIndex] = 0;
    }
    lastIndex--;
}
```
