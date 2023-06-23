class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        # Reverse the order of the words in the list
        words.reverse()
        # Concatenate the words into a string separated by a single space
        return ' '.join(words)