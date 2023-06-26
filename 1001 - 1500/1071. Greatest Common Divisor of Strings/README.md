# GCD of Strings
This repository contains two implementations of the solution to the LeetCode problem 1071 - GCD of Strings. The problem involves finding the greatest common divisor (GCD) of two strings.

## C++ Implementation
### Class: Solution
Member Functions
1. int gcd(int a, int b): This function implements the Euclidean algorithm to find the greatest common divisor of two integers.
2. string gcdOfStrings(string str1, string str2): This function takes two strings as input and returns the greatest common divisor of the strings. It concatenates the strings in different orders and checks if they are equal. If they are not equal, it returns an empty string. Otherwise, it computes the greatest common divisor of the lengths of the strings and returns the substring of str1 from index 0 to gcd_len.

### Example Usage

```
if (__name__ == "__main__") {
    Solution solution;
    string str1 = "ABABAB";
    string str2 = "ABAB";
    string result = solution.gcdOfStrings(str1, str2);
    cout << "Greatest Common Divisor of Strings: " << result << endl;
    str1 = "ABCABC";
    str2 = "ABC";
    result = solution.gcdOfStrings(str1, str2);
    cout << "Greatest Common Divisor of Strings: " << result << endl;
}
```

## Python Implementation
### Class: Solution
Member Functions
1. def gcdOfStrings(self, str1: str, str2: str) -> str: This function takes two strings as input and returns the greatest common divisor of the strings. It concatenates the strings in different orders and checks if they are equal. If they are not equal, it returns an empty string. Otherwise, it computes the greatest common divisor of the lengths of the strings and returns the substring of str1 from index 0 to gcd_len.
2. def gcd(self, a: int, b: int) -> int: This function implements the Euclidean algorithm to find the greatest common divisor of two integers.

### Example Usage
```
if __name__ == "__main__":
    solution = Solution()
    str1 = "ABABAB"
    str2 = "ABAB"
    result = solution.gcdOfStrings(str1, str2)
    print("Greatest Common Divisor of Strings:", result)
    str1 = "ABCABC"
    str2 = "ABC"
    result = solution.gcdOfStrings(str1, str2)
    print("Greatest Common Divisor of Strings:", result)
```