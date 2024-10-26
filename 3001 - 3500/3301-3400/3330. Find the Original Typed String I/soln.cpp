class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1; // Start with one possibility, the original string
        // Iterate through the string to count consecutive identical characters
        for(int i=0; i<word.size()-1; i++) {
            // If the current character is the same as the next one,
            // Increment the count for each consecutive character
            if(word[i] == word[i+1]) count++;
        }
        return count; // Return the total count of possible original strings
    }
};