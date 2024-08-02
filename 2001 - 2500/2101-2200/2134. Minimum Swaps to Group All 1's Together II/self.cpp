// Hint1
// Notice that the number of 1’s to be grouped together is fixed. It is the number of 1's the whole array has.
// Hint2
// Call this number total. We should then check for every subarray of size total (possibly wrapped around), how many swaps are required to have the subarray be all 1’s.
// Hint3
// The number of swaps required is the number of 0’s in the subarray.
// Hint4
// To eliminate the circular property of the array, we can append the original array to itself. Then, we check each subarray of length total.
// Hint5
// How do we avoid recounting the number of 0’s in the subarray each time? The Sliding Window technique can help.

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one_count = 0;
        // count number of 1s
        for(int i=0; i<n; i++) {
            if(nums[i]==1) one_count++;
        }
        // Handle edge cases
        if(one_count == 0 || one_count == n) return 0;
        // append nums to itself
        for(int i=0; i<n; i++) nums.push_back(nums[i]);
        // two pointer approach - make a window of size one_count. Count number of zeros in between.
        // the minimum number of zeros would be the answer
        int l=0, r=0, result=INT_MAX;
        int zeros=0;
        // make the window of size one_count
        for(r=0; r<one_count; r++) {
            if(nums[r]==0) zeros++;
        }
        result = min(result, zeros);
        // slide the window
        for(r=one_count; r<nums.size(); r++) {
            if(nums[l] == 0) zeros--;
            l++;
            if(nums[r] == 0) zeros++;
            result = min(result, zeros);
        }
        return result;  
    }
};