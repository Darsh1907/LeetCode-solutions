// Erasing elements from the vector inside the loop can lead to skipping elements and incorrect results. 
// Instead of erasing elements from the vector directly, you can adopt a different approach to solve the problem 
// without modifying the vector during the iteration.

// One possible solution is to maintain two pointers: i and j. Pointer i iterates over each element in the 
// vector, while pointer j keeps track of the position where the next non-val element should be placed. 
// By copying non-val elements to the correct position, you can achieve the desired result.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0; // Pointer for the next non-val element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i]; // Copy non-val element
                j++;
            }
        }
        return j; // j represents the new length of the modified vector
    }
};