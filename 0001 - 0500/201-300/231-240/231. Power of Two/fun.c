/*
We are literally gonna take the advantage of the constraints. 
I dont recommend you all to use this method during your interviews. 
It's a fun method . Do this on your own, you will enjoy it ;))
*/

// Hint: Constraints [-2^31 <= n <= 2^31 - 1] also 2^30 is 1073741824

bool isPowerOfTwo(int n) {
    if(n==0) return false;
    return (n>0) && (1073741824%n == 0);
}