#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    
    if (strsSize == 0) {
        char *result = (char *)malloc(1 * sizeof(char));
        result[0] = '\0';
        return result;
    }

    int prefixLen = 0;
    int minLen = strlen(strs[0]);

    // Find the minimum length among all strings
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) minLen = len;
    }

    // Iterate over characters in the first string
    for (int i = 0; i < minLen; i++) {
        char currentChar = strs[0][i];
        // Compare the current character with corresponding characters in other strings
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != currentChar) {
                char *result = (char *)malloc((prefixLen + 1) * sizeof(char));
                strncpy(result, strs[0], prefixLen);
                result[prefixLen] = '\0';
                return result;
            }
        }
        prefixLen++;
    }
    char *result = (char *)malloc((prefixLen + 1) * sizeof(char));
    strncpy(result, strs[0], prefixLen);
    result[prefixLen] = '\0';
    return result;
}

int main() {
    // Example usage
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    
    char *prefix = longestCommonPrefix(strs, strsSize);
    printf("Longest common prefix: %s\n", prefix);
    
    // Remember to free the memory allocated for the prefix
    free(prefix);

    return 0;
}