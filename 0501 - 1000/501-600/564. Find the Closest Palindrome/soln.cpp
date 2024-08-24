// https://leetcode.com/problems/find-the-closest-palindrome/solutions/5675172/o-1-beats-100-0-ms-c-java-python-go-rust-javascript/?envType=daily-question&envId=2024-08-24

class Solution {
    long long generatePalindromeFromLeft(long long leftHalf, bool isEvenLength) {
        long long palindrome = leftHalf;
        if (!isEvenLength) leftHalf /= 10;
        while (leftHalf > 0) {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
public:
    string nearestPalindromic(string numberStr) {
        long long number = stoll(numberStr);
        if (number <= 10) return to_string(number - 1);
        if (number == 11) return "9";
        int length = numberStr.length();
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));
        vector<long long> palindromeCandidates(5);
        int isEvenLength = (length%2 == 0);
        palindromeCandidates[0] = generatePalindromeFromLeft(leftHalf - 1, isEvenLength);
        palindromeCandidates[1] = generatePalindromeFromLeft(leftHalf, isEvenLength);
        palindromeCandidates[2] = generatePalindromeFromLeft(leftHalf + 1, isEvenLength);
        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;
        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;
        for (long long candidate : palindromeCandidates) {
            if (candidate == number) continue;
            long long difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }
        return to_string(nearestPalindrome);
    }
};