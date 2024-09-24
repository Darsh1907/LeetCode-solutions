// It is known that a perfect square will have only 1 high bit in its binary form.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)return false;
        int bits = __builtin_popcount(n);
        if(bits==1) return true;
        return false;
    }
};