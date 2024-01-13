#include <stdio.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    
    int sLen = strlen(s);
    if(sLen == 0) return true;

    int tLen = strlen(t);
    if(sLen > tLen) return false;

    int j = 0; // pointer for s
    for(int i = 0; i < tLen; i++) { // i acts as pointer for t
        if(j == sLen) return true;
        if(t[i] == s[j]) j++;
    }
    return (j == sLen); // Check if all characters of s have been found
}

int main() {
    char s[] = "abc";
    char t[] = "ahbgdc";
    if (isSubsequence(s, t)) printf("%s is a subsequence of %s\n", s, t);
    else printf("%s is not a subsequence of %s\n", s, t);
    return 0;
}