// A trailing zero is always produced by prime factors 2 and 5. 
// No. of 2 is always greater than 5 in factorial. 
// A simple way is to calculate floor(n/5).
// But, numbers like 25, 125, etc have more than 5 instead of floor (n / 5). 
// Handling this is simple, first, divide n by 5 and get all single 5s, then divide by 25 to get extra 5s, and so on.

int trailingZeroes(int n) {
    int ans = 0;
    for(int i=5; i<=n; i*=5) ans = ans + n/i;
    return ans;
}