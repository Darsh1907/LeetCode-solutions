class Solution {
public:
    int minAllOneMultiple(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int rem = 0;
        for (int length = 1; length <= k; length++) {
            rem = (rem * 10 + 1) % k; // keeping track of remainder.
            if (rem == 0) return length; // return when remainder becomes 0
        }
        return -1;
    }
};