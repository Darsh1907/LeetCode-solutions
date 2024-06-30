class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // initialize a min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        // make a heap of k elements
        for(int i=0; i<k; i++) pq.push(nums[i]);
        // update heap such that the heap will only contain the k largest elements
        for(int i=k; i<nums.size(); i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};