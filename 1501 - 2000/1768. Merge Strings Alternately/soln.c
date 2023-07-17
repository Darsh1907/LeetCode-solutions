#include <stdio.h>
#include <stdlib.h>

char* mergeAlternately(char* word1, char* word2) {

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int size = len1 + len2;
    char* result = (char*)malloc((size + 1) * sizeof(char));

    int i, j, k;
    i = j = k = 0;

    while (i<len1 && j<len2) {
        result[k] = word1[i];
        k++;
        i++;
        result[k] = word2[j];
        k++;
        j++;
    }

    while (i < len1){
        result[k] = word1[i];
        k++;
        i++;
    }

    while (j < len2){
        result[k] = word2[j];
        k++;
        j++;
    } 

    result[k] = '\0';

    return result;
}

int main() {
    // Test case 1
    char word1[] = "abc";
    char word2[] = "def";
    char* result1 = mergeAlternately(word1, word2);
    printf("Result 1: %s\n", result1);
    // Test case 2
    char word3[] = "abcd";
    char word4[] = "efgh";
    char* result2 = mergeAlternately(word3, word4);
    printf("Result 2: %s\n", result2);
    // Add more test cases as needed
    return 0;
}