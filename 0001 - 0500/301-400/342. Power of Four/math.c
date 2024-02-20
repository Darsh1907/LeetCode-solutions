bool isPowerOfFour(int n) {
    double log_val = log(n)/log(4);
    if(log_val==(int)log_val) return true;
    return false;
}