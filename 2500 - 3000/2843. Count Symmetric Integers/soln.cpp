class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; ++num) {
            if (isSymmetric(num)) count++;
        }
        return count;
    }
    
    bool isSymmetric(int num) {
        // Convert the integer to a string for easy manipulation
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Check if the number of digits is even (symmetric numbers only)
        if(n%2 == 1) return false;
        
        int leftSum = 0;
        int rightSum = 0;
        
        // Calculate the sum of the first half and second half of the digits
        for (int i=0; i<n/2; i++) {
            leftSum += (numStr[i] - '0');
            rightSum += (numStr[n-1-i] - '0');
        }
        
        // Check if the sums are equal
        return leftSum == rightSum;
    }
};