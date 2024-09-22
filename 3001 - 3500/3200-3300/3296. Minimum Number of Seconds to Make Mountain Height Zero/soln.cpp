class Solution {
private:
    // Function to check if a given time `T` is sufficient for the workers to reduce the mountainHeight
    bool canReduceInTime(long long T, vector<int>& workerTimes, int mountainHeight) {
        long long totalHeightReduced = 0;
        for (int time : workerTimes) {
            // Use quadratic formula to calculate the maximum height this worker can reduce
            // within time T: workerTimes[i] * (h * (h + 1)) / 2 <= T
            long long low = 0, high = mountainHeight;
            while (low < high) {
                long long mid = (low + high + 1) / 2;
                if (1LL * time * mid * (mid + 1) / 2 <= T)
                    low = mid;
                else high = mid - 1;
            }
            totalHeightReduced += low;
            if (totalHeightReduced >= mountainHeight) return true;
        }
        return totalHeightReduced >= mountainHeight;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18;
        // Perform binary search to find the minimum time
        while (left < right) {
            long long mid = (left + right) / 2;
            if (canReduceInTime(mid, workerTimes, mountainHeight)) right = mid; // Try for a smaller time
            else left = mid + 1; // Need more time
        }
        return left;
    }
};