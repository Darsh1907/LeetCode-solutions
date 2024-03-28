# 148. Sort List
## (Medium)

Given the `head` of a linked list, return the list *after sorting* it in **ascending order**.
 

Example 1:

![alt text](image.png)

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

Example 2:

![alt text](image-1.png)

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

Example 3:

```
Input: head = []
Output: []
```

**Constraints**:

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`
 

**Follow up**: Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?