class Solution {
    bool isPrime(int n) {
        // Handle edge cases
        if (n == 1) return false;
        if (n <= 3) return true; // 2 and 3 are prime
        // Exclude multiples of 2 and 3
        if (n % 2 == 0 || n % 3 == 0) return false;
        // Check for factors from 5 to sqrt(n)
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
public:
    int nonSpecialCount(int l, int r) {
        double rootl_temp = sqrt(l);
        int rootl = ceil(rootl_temp);
        int rootr = sqrt(r);
        int count = 0;
        for(int i=rootl; i<=rootr; i++) {
            if(isPrime(i)) count++;
        }
        return (r - l + 1 - count);
    }
};