class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() <= 4) return 0;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<4; i++) {
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
        }
        for(int i=4; i<n; i++) {
            maxHeap.push(nums[i]);
            minHeap.push(nums[i]);
            maxHeap.pop();
            minHeap.pop();
        }
        vector<int> temp(min(n, 8));
        int t = temp.size();
        int l=3, r=t-4;
        for(int i=0; i<4; i++) {
            temp[l--] = maxHeap.top();
            maxHeap.pop();
        }
        for(int i=0; i<4; i++) {
            temp[r++] = minHeap.top();
            minHeap.pop();
        }
        return min(min(temp[t-1]-temp[3], temp[t-2]-temp[2]), min(temp[t-3]-temp[1], temp[t-4]-temp[0]));
    }
};