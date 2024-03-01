bool match(int* count, int* temp) {
    for (int i = 0; i < 26; i++) {
        if (count[i] != temp[i]) return false;
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    
    if (s1_len > s2_len) return false;

    int count[26] = {0};
    for (int i = 0; i < s1_len; i++) count[s1[i] - 'a']++;
    
    int temp[26] = {0};
    for (int i = 0; i < s1_len; i++) temp[s2[i] - 'a']++;

    if (match(count, temp)) return true;

    for (int i = s1_len; i < s2_len; i++) {
        temp[s2[i - s1_len] - 'a']--;
        temp[s2[i] - 'a']++;
        if (match(count, temp)) return true;
    }

    return false;
}