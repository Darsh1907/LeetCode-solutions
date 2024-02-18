we will assume this given array as a linkedlist and then we can solve it using the idea of cycle in a linked list.
<br>
since we know there is a repeated element therefore there will always be a cycle and starting element of the cycle is always the repeated element let understand this in detail.
<br>
Since there is a duplicate number that means there will be definetely a cycle that mean fast and slow meet each other or we can also say since fast and slow meet therefore there is a cycle.
<br>
when we move fast by 2steps and slow by 1step
<br>
this can be simply done using the find cycle in the linkedlist approach, please refer to the idea of that
from here Linked List Cycle
<br>
here updating slow pointer will be done as
<br>
slow = nums[slow]; // by 1 steps
<br>
fast pointer will be updated as
<br>
fast = nums[nums[fast]]; // by 2 steps
<br>
so now we are at a point where they both meet and hence the first collision point.
<br>
Now to find the starting of cycle , i.e
The second collision is when we move both the pointer by 1 (For Finding the Starting point)
<br>
but before that when are fast and slow pointer meets then the slow pointer have covered a dist of let say x, and the fast pointer have covered the dist of 2x. So the difference of distance travel by both fast and slow is x, and we can say this x is the multiple of the length of the cycle because fast and slow are meeting at any point in the cycle and they will only meet if differece of distance between them is a multiple of length of cycle.
<br>
so for finding the second collision we keep the fast pointer at start and the slow remains at the first collison point and now both will move by 1 steps till both slow and fast becomes equal, and now slow will be the start of the cycle and is the repeated element.
<br>
so now the question is when both fast and slow meet again how it be the starting element of linkedlist ?
<br>
as i proved earlier that the difference of distance of fast and slow is x (multilple of length of cycle), so when they meet the fast pointer has already moved an extra x(dist) than slow and we can easily say x is the multiple of length of cycle.
<br>
x = n C (x is a multiple of length of Cycle C)
<br>
now assume the distance from start to duplicate is 'a' so the distance from duplicate to first collision is 'x - a';
<br>
now to find the second collison we are keeping the fast pointer at start and moving fast and slow by 1, so now if the duplicate is at dist a so the fast pointer will move a dist of a and the slow pointer is at x - a it will also move a dist of a
i.e x - a + a that is x and this x is the multiple of lenght of cycle so we can say that when we start fast pointer from starting point and slow pointer from first collison point they are bound to meet at the duplicate element i.e the start of the cycle.
<br>

- Time Complexity -> O(N)
- Space Complextiy -> O(1)

```
int findDuplicate(int* nums, int numsSize) {
    int fast = nums[0];
    int slow = nums[0];
    do{
        fast = nums[nums[fast]];
        slow = nums[slow];
    }while(fast != slow);
    fast = nums[0];
    while(fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}
```