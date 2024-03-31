#include <stdio.h>

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

int main() {
    int possible[] = {1, 0, 1, 1, 0};
    int possibleSize = sizeof(possible) / sizeof(possible[0]);
    int result = minimumLevels(possible, possibleSize);
    printf("Minimum levels: %d\n", result);
    return 0;
}