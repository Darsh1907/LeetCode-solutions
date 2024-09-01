class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> results;
        priority_queue<int> maxHeap;
        for (const auto& query : queries) {
            int x = query[0];
            int y = query[1];
            int distance = abs(x) + abs(y);
            if(maxHeap.size() < k) maxHeap.push(distance);
            else if (distance < maxHeap.top()) {
                maxHeap.push(distance);
                maxHeap.pop();
            }
            if (maxHeap.size() < k) results.push_back(-1);
            else results.push_back(maxHeap.top());
        }
        return results;
    }
};