// This approach uses Binary Search
// This question is similar to the Book Allocation Problem solved on https://www.youtube.com/watch?v=YTTdLgyqOLY&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=15

class Solution {
public:

    bool isPossible(vector<int>& weights, int days, int mid){
        int dayCount = 1;
        int weightSum = 0;
        for(int i=0; i<weights.size(); i++){
            if(weightSum + weights[i] <= mid) weightSum = weightSum + weights[i];
            else {
                dayCount++;
                if(dayCount > days || weights[i] > mid ) return false;
                weightSum = weights[i]; // Reseting the weightsum
            }
            if(dayCount>days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int s = 0;
        int e = 0;
        for(int i=0; i<weights.size(); i++) e = e+weights[i];

        int mid = (e-s)/2;
        int ans = -1;

        while(s<=e){
            if(isPossible(weights, days, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};