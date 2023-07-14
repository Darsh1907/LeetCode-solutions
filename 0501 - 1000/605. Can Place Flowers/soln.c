#include <stdio.h>

int canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbedSize-1 || flowerbed[i+1]==0)) {
            flowerbed[i] = 1;
            count++;
        }
    }
    return count >= n;
}

int main() {
    // Example usage
    int flowerbed[] = {1, 0, 0, 0, 1};
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]);
    int n = 1;
    int canPlace = canPlaceFlowers(flowerbed, flowerbedSize, n);
    printf("Can place flowers: %s\n", canPlace ? "Yes" : "No");
    return 0;
}