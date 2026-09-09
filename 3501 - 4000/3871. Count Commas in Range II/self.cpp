class Solution {
public:
    long long countCommas(long long n) {
        long long resp = 0;
        // since 1 <= n <= 10^15, we can directly do this.
        if(n > 999) resp += (n-999);
        if(n > 999999) resp += (n-999999);
        if(n > 999999999) resp += (n-999999999);
        if(n > 999999999999) resp += (n-999999999999);
        if(n > 999999999999999) resp += (n-999999999999999);
        return resp;
    }
};