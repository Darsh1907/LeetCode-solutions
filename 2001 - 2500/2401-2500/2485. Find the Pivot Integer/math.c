// The logic comes from a mathematical derivation which is given in README.
int pivotInteger(int n) {
    int sum = n * (n + 1) / 2; // Calculate the sum using integer arithmetic
    int sqrtSum = sqrt(sum); // Calculate the integer square root
    // Check if the square of the integer is equal to the sum
    if (sqrtSum * sqrtSum != sum) return -1;
    return sqrtSum;
}