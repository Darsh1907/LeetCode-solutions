// Hint1: The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
// Hint2: An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
// Hint3: The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
// Hint4: Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n);
        res[0] = 1;
        int i2=0, i3=0, i5=0;
        int next2=2, next3=3, next5=5;
        for(int i=1; i<n; i++) {
            int nextUgly = min({next2, next3, next5});
            res[i] = nextUgly;
            if(nextUgly==next2) {
                i2++;
                next2 = res[i2]*2;
            }
            if(nextUgly == next3) {
                i3++;
                next3 = res[i3]*3;
            }
            if(nextUgly==next5) {
                i5++;
                next5 = res[i5]*5;
            }
        }
        return res[n-1];
    }
};