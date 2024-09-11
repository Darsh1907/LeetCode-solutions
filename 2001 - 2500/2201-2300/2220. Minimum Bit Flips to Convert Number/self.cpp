class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start^goal;
        return __builtin_popcount(temp);
    }
};