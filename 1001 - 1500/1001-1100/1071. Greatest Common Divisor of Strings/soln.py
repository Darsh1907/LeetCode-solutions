class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            # If the concatenation of str1 and str2 is not equal to the concatenation of str2 and str1,
            # then there is no common divisor, so return an empty string
            return ""

        # Find the greatest common divisor of the lengths of str1 and str2
        gcd_len = self.gcd(len(str1), len(str2))
        
        return str1[:gcd_len]
    
    def gcd(self, a: int, b: int) -> int:
        # Euclidean algorithm to find the greatest common divisor
        while b:
            a, b = b, a % b
        return a

# Example usage
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