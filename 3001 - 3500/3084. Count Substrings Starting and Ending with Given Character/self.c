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