int min(int a, int b){
    if(a<=b) return a;
    return b;
}

char* getSmallestString(char* s, int k) {
    int size = strlen(s);
    int index = 0;
    while(k && index<size) {
        char c = s[index];
        int distToA = c-'a';
        int distToCycleA = 'z'-c+1;
        // Choose the minimum distance to change the character to 'a'
        int minDist = min(distToA, distToCycleA);
        // If remaining distance 'k' is less than the minimum distance
        if (k < minDist) {
            s[index] -= k; // Update the character to minimize distance
            k=0; // Set remaining distance to 0
        } 
        else {
            s[index] = 'a'; // Update the character to 'a'
            k -= minDist; // Subtract the minimum distance from 'k'
        }
        index++;
    }
    return s;
}