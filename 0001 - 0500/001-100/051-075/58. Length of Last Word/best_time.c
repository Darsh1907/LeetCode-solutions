int lengthOfLastWord(char* s) {
    int length = 0;
    int lastWord = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] != ' '){
            length ++;
            lastWord = length;
        }
        else length = 0;
    }
    return lastWord;
}