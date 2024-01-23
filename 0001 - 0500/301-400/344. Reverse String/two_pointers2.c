void reverseString(char* s, int sSize) {
    int l = 0;
    int h = sSize-1;
    while(l<h) {
        s[l] = s[l] + s[h];
        s[h] = s[l] - s[h];
        s[l] = s[l] - s[h];
        l++;
        h--;
    }
}