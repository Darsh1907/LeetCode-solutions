class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        i = len(s) - 1
        while i >= 0:
            if count == 0 and s[i] == ' ':
                count = 0
            elif s[i] != ' ':
                count += 1
            elif s[i] == ' ' and count != 0:
                break
            i -= 1
        return count

def main():
    # Example usage
    s = "Hello World"

    solution = Solution()
    length = solution.lengthOfLastWord(s)

    print("Length of last word:", length)


if __name__ == "__main__":
    main()