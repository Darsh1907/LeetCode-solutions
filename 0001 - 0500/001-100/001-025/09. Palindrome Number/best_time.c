// Function to count the number of digits in a given number
static int count_digits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Function to check if a number is palindrome
bool isPalindrome(int x) {
    // Check for negative numbers
    if (x < 0)
        return false;

    // Count the number of digits in the number
    int num_digits = count_digits(x);

    // Allocate memory for an array to store digits
    int *digits = (int *)malloc(num_digits * sizeof(int));
    if (digits == NULL)
        return false;

    // Extract digits of the number and store them in the array
    int i = 0;
    int original = x;
    while (x > 0) {
        digits[i++] = x % 10;
        x /= 10;
    }

    // Check if the number is a palindrome
    int left = 0;
    int right = num_digits - 1;
    while (left < right) {
        if (digits[left] != digits[right]) {
            free(digits);
            return false;
        }
        left++;
        right--;
    }

    // Free dynamically allocated memory
    free(digits);

    return true;
}