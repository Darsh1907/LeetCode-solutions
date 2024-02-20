bool isPowerOfThree(int n) {
    if(n<=0) return false;
    double logval = log10(n)/log10(3);
    return (logval == ceil(logval));
}