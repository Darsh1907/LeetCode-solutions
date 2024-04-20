int sumOfUnique(int* nums, int numsSize) {
    int frequency[101] = {0}; // Assuming the range of elements is [1, 100]
    int sum = 0;
    // Count the frequency of each element in the array
    for (int i = 0; i < numsSize; i++) {
        frequency[nums[i]]++;
    }
    // Sum up the unique elements
    for (int i = 1; i <= 100; i++) {
        if(frequency[i] == 1) sum += i;
    }
    return sum;
}