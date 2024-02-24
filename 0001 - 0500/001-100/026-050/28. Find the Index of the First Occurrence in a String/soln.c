int strStr(char* haystack, char* needle) {
    int n_size = strlen(needle);
    int h_size = strlen(haystack);

    if (n_size > h_size) return -1;

    for (int i = 0; (i + n_size - 1) < h_size; i++) {
        if (haystack[i] == needle[0]) {
            if (strncmp(&haystack[i], needle, n_size) == 0) return i;
        }
    }

    return -1;
}