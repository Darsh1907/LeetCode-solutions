class Solution {
public:
    vector<int> countBits(int n) {
        /**
         * The key insight: i & (i - 1) set the rightmost 1 to zero if i is unsigned or
         * positve.
         * Index is unsigned int.
         * one_cnt of i = one_cnt of (i & (i - 1)) + 1
         */
        vector<int> ones_cnt(n + 1, 0);
        /* Note that ones_cnt[0] = 0 */
        for (size_t i = 1; i < ones_cnt.size(); i++) {
            ones_cnt[i] = 1 + ones_cnt[i & (i - 1)];
        }
        return ones_cnt;
    }
};