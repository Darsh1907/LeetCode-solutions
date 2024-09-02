int chalkReplacer(int* chalk, int chalkSize, int k) {
    long long arr_sum = 0;
    // Compute total sum of chalk
    for (int i=0; i<chalkSize; i++) arr_sum += chalk[i];
    // Reduce k by modulo of total sum of chalk
    k = k % arr_sum;
    // Iterate through the chalk array to find the student who will replace the chalk
    for (int i = 0; i < chalkSize; i++) {
        if (chalk[i] > k) return i;
        k -= chalk[i];
    }
    return -1; // Just a fallback, ideally this line should never be reached.
}