// Function to find the minimum and maximum days in bloomDay array
void getMinMax(int* bloomDay, int bloomDaySize, int* minDay, int* maxDay) {
    *minDay = INT_MAX;
    *maxDay = INT_MIN;
    for (int i = 0; i < bloomDaySize; i++) {
        if(bloomDay[i] < *minDay) *minDay = bloomDay[i];
        if(bloomDay[i] > *maxDay) *maxDay = bloomDay[i];
    }
}

// Function to check if we can make 'm' bouquets in 'num' days
bool check(int num, int* bloomDay, int bloomDaySize, int m, int k) {
    int bouquets = 0;
    int flowers = 0;
    for (int i = 0; i < bloomDaySize; i++) {
        if (bloomDay[i] <= num) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } 
        else flowers = 0;
        if (bouquets >= m) return true;
    }
    return (bouquets >= m);
}

// Function to find the minimum days required to make 'm' bouquets
int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if ((long)m * k > bloomDaySize) return -1;
    int minDay, maxDay;
    getMinMax(bloomDay, bloomDaySize, &minDay, &maxDay);
    int s = minDay;
    int e = maxDay;
    int res = e;
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (check(mid, bloomDay, bloomDaySize, m, k)) {
            res = mid;
            e = mid;
        } 
        else s = mid + 1;
    }
    return res;
}