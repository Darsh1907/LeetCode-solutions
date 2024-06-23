class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size(), i=0, j=0, maxLen=0;
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        while (j < n) {
            maxHeap.push({nums[j], j});
            minHeap.push({nums[j], j});
            int diff = maxHeap.top().first - minHeap.top().first;
            while (i <= j && diff > limit) {
                i = min(maxHeap.top().second, minHeap.top().second) + 1;
                while (!maxHeap.empty() && maxHeap.top().second < i) maxHeap.pop();
                while (!minHeap.empty() && minHeap.top().second < i) minHeap.pop();
                if (!maxHeap.empty() && !minHeap.empty()) {
                    diff = maxHeap.top().first - minHeap.top().first;
                }
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};