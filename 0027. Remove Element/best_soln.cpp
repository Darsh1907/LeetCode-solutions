class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Part 1 - Find K
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
            else k++;
        }
        return k;
    }
};

// The provided solution uses a two-part approach to solve the "Remove Element" problem.

// Part 1:
// The first part of the solution aims to find the value of k, which represents the number of elements in the modified 
// vector after removing all occurrences of val. The variable k is initialized to 0.

// The solution iterates over each element in the nums vector using a for loop. If the current element is equal to 
// val, it is removed from the vector using the erase function, which takes an iterator pointing to the element to 
// be removed. After erasing an element, the loop variable i is decremented by one to ensure that the same index is 
// revisited in the next iteration.

// On the other hand, if the current element is not equal to val, it means the element should be kept in the 
// modified vector. In this case, the variable k is incremented to track the count of non-val elements.

// At the end of this part, the vector nums has all instances of val removed, and k holds the count of non-val 
// elements.

// Part 2:
// The second part of the solution simply returns the value of k, representing the length of the modified vector.

// Overall, this solution effectively removes all occurrences of val from the vector and returns the count of 
// non-val elements. However, it's worth noting that modifying the vector during the iteration, as done in this 
// solution, can lead to performance issues for larger inputs. The approach using two pointers, as described in 
// the previous response, is more efficient in such cases.