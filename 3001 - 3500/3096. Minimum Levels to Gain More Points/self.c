int minimumLevels(int* possible, int possibleSize) {
    int total_sum = 0;
    for(int i=0; i<possibleSize; i++){
        if(possible[i]==0) possible[i] =- 1;
        total_sum += possible[i];
    }
    int dan = possible[0];
    int bob = total_sum - possible[0];
    if(dan>bob) return 1;
    int i=1;
    while(dan<=bob && i<possibleSize) {
        dan += possible[i];
        bob -= possible[i];
        i++;
    }
    if(i==possibleSize) return -1;
    return i;
}