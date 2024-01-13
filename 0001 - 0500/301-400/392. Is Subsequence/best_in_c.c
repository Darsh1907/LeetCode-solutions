#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    if(*s == '\0') return true;
    if(*t == '\0') return false;
    if (*s == *t) return isSubsequence(s + 1, t + 1); 
    else return isSubsequence(s, t + 1);
}

int main() {
    char s[] = "abc";
    char t[] = "ahbgdc";
    if (isSubsequence(s, t)) printf("%s is a subsequence of %s\n", s, t);
    else printf("%s is not a subsequence of %s\n", s, t);
    return 0;
}