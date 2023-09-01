#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int count = 0;
    int length = strlen(s);
    
    for (int i = length - 1; i >= 0; i--) {
        if (count == 0 && s[i] == ' ')
            count = 0;
        else if (s[i] != ' ')
            count++;
        else if (s[i] == ' ' && count != 0)
            break;
    }
    
    return count;
}

int main() {
    // Example usage
    char s[] = "Hello World";
    
    int length = lengthOfLastWord(s);
    
    printf("Length of last word: %d\n", length);
    
    return 0;
}