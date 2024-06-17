/*
Approach: Binary search the number such that divind num by that number gives the number itself

Time Complexity: log(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;  // Handle the case where num is 1
        int l = 1, r = num;
        while (l <= r) {  // Use l <= r to cover the entire search space
            int m = l + (r - l) / 2;
            long long square = (long long)m * m;  // Use long long to avoid overflow
            if (square == num) return true;
            else if (square < num) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
};