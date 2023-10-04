class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // STL map to store number of subarrays starting from
        // index zero having particular value of sum.
        unordered_map<int, int> prevSum;
        int res = 0;
        // Sum of elements so far.
        int currSum = 0;
        for (int i=0; i<nums.size(); i++) {
            // Add current element to sum so far.
            currSum += nums[i];
            // If currsum is equal to desired sum, then a new
            // subarray is found. So increase count of
            // subarrays.
            if(currSum==k) res++;
            // currsum exceeds given sum by currsum  - sum. Find
            // number of subarrays having this sum and exclude
            // those subarrays from currsum by increasing count by same amount.
            if(prevSum.find(currSum-k)!=prevSum.end()) res+=(prevSum[currSum-k]);
            // Add currsum value to count of different values of sum.
            prevSum[currSum]++;
        }
        return res;
    }
};