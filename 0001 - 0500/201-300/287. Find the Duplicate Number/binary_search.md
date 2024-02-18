## APPROACH 4 USING BINARY SEARCH

- Time Complexity -> O(N Log N)
- Space Complexit -> O(1)

**ALGORITHM**

- Perform Binary Search on range 1 to n;
- low = 1, high = nums.size() - 1;
- While the value of high is greater than or equal to low:
- - calculate mid.
- - count elements <= to mid.
- - if count is less than equal to mid:
- - - low = mid + 1 (binary search on right half)
- - - else high = mid + 1 (binary search on left half)
- Return low which will point to duplicate.