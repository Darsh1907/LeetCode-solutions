int getReverseIndex(char ch) {return -1 * (ch - ('z'+1));}

int getCharacterScore(char ch, int ind) {return getReverseIndex(ch) * ind;}

int reverseDegree(char* s) {
    int i=1;
    int res=0;
    while(*s) {
        res += getCharacterScore(*s, i);
        i++;
        s++;
    }
    return res;
}