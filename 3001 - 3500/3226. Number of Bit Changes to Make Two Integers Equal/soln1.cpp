class Solution {
public:
    int minChanges(int n, int k) {
        // If there are bits in k that are 1 but not in n, return -1
        if ((k & ~n) != 0) return -1;
        // Count the number of 1 bits in n that need to be changed to 0 to match k
        int changes = 0;
        // XOR to find the bits that differ
        int diff = n ^ k;
        while (diff) {
            // Check if the least significant bit is different
            if (diff & 1) changes++;
            diff >>= 1; // Shift right to check the next bit
        }
        return changes;
    }
};