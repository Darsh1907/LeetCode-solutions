bool is_vowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

bool halvesAreAlike(char* s) {
    int mid = strlen(s)/2, vowel_count = 0;
    for(int i = 0; i<mid; i++) {
        if(is_vowel(s[i])) vowel_count++;
        if(is_vowel(s[mid+i])) vowel_count--;
    }
    return (vowel_count==0);
}