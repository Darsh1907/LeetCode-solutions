class Solution {
public:
    int bitwiseComplement(int num) {
        if (num == 0) return 1; 
        unsigned int bitmask = ~0; // binary number with all 1s (mask)
        // left shift till AND operation yields 0
        while (num & bitmask) bitmask <<= 1;
        // perform xor with complement of mask
        return num ^ ~bitmask;
    }
};