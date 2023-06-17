// Erasing elements from the vector inside the loop can lead to skipping elements and incorrect results. 
// Instead of erasing elements from the vector directly, you can adopt a different approach to solve the problem 
// without modifying the vector during the iteration.

// One possible solution is to maintain two pointers: i and j. Pointer i iterates over each element in the 
// vector, while pointer j keeps track of the position where the next non-val element should be placed. 
// By copying non-val elements to the correct position, you can achieve the desired result.

#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    // Example usage
    vector<int> nums = {3, 2, 2, 3, 1, 4, 2, 3};
    int val = 2;
    
    Solution solution;
    int length = solution.removeElement(nums, val);
    
    cout << "New length: " << length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}