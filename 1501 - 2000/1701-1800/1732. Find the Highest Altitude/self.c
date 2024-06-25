int max(int a, int b) {if(a>=b) return a; return b;}

int largestAltitude(int* gain, int gainSize) {
    int level = 0;
    int maxLevel = 0;
    for(int i=0; i<gainSize; i++) {
        level += gain[i];
        maxLevel = max(level, maxLevel);
    }
    return maxLevel;
}