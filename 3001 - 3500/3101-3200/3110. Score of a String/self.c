int scoreOfString(char* s) {
    int score = 0;
    int size = strlen(s);
    for(int i=1; i<size; i++) score += abs(s[i]-s[i-1]);
    return score;
}