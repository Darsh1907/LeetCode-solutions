// This approach uses Binary Search
// This question is similar to the Book Allocation Problem solved 
// on https://www.youtube.com/watch?v=YTTdLgyqOLY&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=15

#include <stdbool.h>

bool isPossible(int* weights, int weightsSize, int days, int mid){
    int dayCount = 1;
    int weightSum = 0;
    for(int i=0; i<weightsSize; i++){
        if(weightSum + weights[i] <= mid) weightSum = weightSum + weights[i];
        else {
            dayCount++;
            if(dayCount > days || weights[i] > mid ) return false;
            weightSum = weights[i];
        }
        if(dayCount>days) return false;
    }
    return true;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int n = weightsSize;
    int s = 0;
    int e = 0;
    for(int i=0; i<weightsSize; i++) e = e+weights[i];
    int mid = (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(weights, weightsSize, days, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else s = mid + 1;
        mid = s + (e-s)/2;
    }
    return ans;  
}