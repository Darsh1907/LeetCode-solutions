#include <stdio.h>
#include <string.h>

long long countSubstrings(char* s, char c) {
    long long count = 0;
    int n = strlen(s);
    int occurrences = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == c) {
            occurrences++;
            count += occurrences;
        }
    }
    return count;
}

int main() {
    char str[] = "example string";
    char target = 'e';
    long long result = countSubstrings(str, target);
    printf("Number of substrings starting and ending with '%c': %lld\n", target, result);
    return 0;
}