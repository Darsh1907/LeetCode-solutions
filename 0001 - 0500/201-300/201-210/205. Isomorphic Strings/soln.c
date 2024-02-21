#define MAX_CHAR 256

bool isIsomorphic(char* s, char* t) {
    int s_size = strlen(s);
    if (s_size != strlen(t)) return false;
    char charMapST[MAX_CHAR] = {0};
    char charMapTS[MAX_CHAR] = {0};
    for (int i = 0; i < s_size; i++) {
        char c1 = s[i];
        char c2 = t[i];
        if (charMapST[c1] == 0 && charMapTS[c2] == 0) {
            charMapST[c1] = c2;
            charMapTS[c2] = c1;
        } 
        else if (charMapST[c1] != c2 || charMapTS[c2] != c1) return false;
    }
    return true;
}