class Solution {
public:
    int countCommas(int n) {
        // range is upto 10^5 so this works
        return max(n - 999, 0);
    }
};