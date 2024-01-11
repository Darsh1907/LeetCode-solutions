int lengthOfLastWord(char* s) {
    int i = strlen(s)-1;
    // Skip trailing whitespaces
    while (i>=0 && s[i]==' ') i--;
    int count = 0;
    // Count the length of the last word
    while (i>=0 && s[i]!=' ') {
        count++;
        i--;
    }
    return count;
}